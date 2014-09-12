# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird
DISTVERSION=	31.1.0
PORTREVISION=	1
CATEGORIES=	mail news net-im ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		https://ftp.mozilla.org/pub/mozilla.org/${PORTNAME}/candidates/${DISTVERSION}-candidates/build2/source/
DISTFILES=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

BUILD_DEPENDS=	nspr>=4.10.6:${PORTSDIR}/devel/nspr \
		nss>=3.16:${PORTSDIR}/security/nss \
		soundtouch>=1.8.0:${PORTSDIR}/audio/soundtouch \
		harfbuzz>=0.9.25:${PORTSDIR}/print/harfbuzz \
		graphite2>=1.2.4:${PORTSDIR}/graphics/graphite2 \
		libvorbis>=1.3.4:${PORTSDIR}/audio/libvorbis \
		opus>=1.1:${PORTSDIR}/audio/opus \
		libvpx>=1.3.0:${PORTSDIR}/multimedia/libvpx \
		sqlite3>=3.8.4.2:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
#		cairo>=1.12.16,2:${PORTSDIR}/graphics/cairo \

LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

EM_VERSION=	1.7.2
L_VERSION=	3.3.1

SSP_UNSAFE=	yes
USE_AUTOTOOLS=	autoconf213:env
OBJDIR_BUILD=	# in-tree build broken after bug 789837
USE_GECKO=	gecko
USE_MOZILLA=	-cairo

WANT_GNOME=	yes
USE_QT5=	# empty
QT_NONSTANDARD=	yes
ALL_TARGET=	default
USE_GL=		gl
USES=		dos2unix tar:bzip2 compiler:features
DOS2UNIX_FILES=	mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp

MOZ_OPTIONS=	--program-transform-name='s/thunderbird/${MOZILLA}/' \
	--enable-single-profile --disable-profilesharing \
	--enable-application=mail --enable-official-branding
MOZ_MK_OPTIONS=	MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1
MOZ_EXPORT=		MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1
MOZ_PKGCONFIG_FILES=

PORTNAME_ICON=	${MOZILLA}.png
PORTNAME_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png

SYSTEM_PREFS=	${FAKEDIR}/lib/${PORTNAME}/defaults/pref/${PORTNAME}.js
MOZ_PIS_SCRIPTS=moz_pis_S50cleanhome

OPTIONS_DEFINE=	ENIGMAIL LIGHTNING
OPTIONS_DEFAULT=ENIGMAIL LIGHTNING

# non-client.mk objdir build broken after bug 846540
.undef GNU_CONFIGURE
ALL_TARGET=	build
MAKEFILE=	${WRKSRC}/client.mk

.include "${.CURDIR}/../../www/firefox/Makefile.options"

OPTIONS_DEFAULT:=${OPTIONS_DEFAULT:S/GSTREAMER//}

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/comm-esr31
MOZSRC:=	${WRKSRC}/mozilla

XPI_LIBDIR=	${PREFIX}/lib/xpi

# avoid clang 3.2/3.3 crash in js/src/jsgc.cpp on refillFreeList<(js::AllowGC)1>
# http://svnweb.freebsd.org/changeset/base/255804
.if ${CHOSEN_COMPILER_TYPE} == clang && ${ARCH} == i386 && ${OSVERSION} < 1000056
. if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
BROKEN=		Cannot build with OPTIMIZED_CFLAGS option due to \
		a ${CHOSEN_COMPILER_TYPE} bug: unset the option or \
		use FAVORITE_COMPILER=gcc in Makefile.local/make.conf
# apply workaround only for -O2 or greater
. elif ${CXXFLAGS:M-O*} && ! ${CXXFLAGS:M-O[01]}
.  if ${MACHINE_CPU:Msse2}
CXXFLAGS+=	-msse2
.  else
CXXFLAGS+=	-O1
.  endif
. endif
.endif

.if ${PORT_OPTIONS:MALSA}
RUN_DEPENDS+=	alsa-lib>=1.0.27.2_1:${PORTSDIR}/audio/alsa-lib
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
RUN_DEPENDS+=	gstreamer1-libav>=1.2.4_1:${PORTSDIR}/multimedia/gstreamer1-libav
.endif

.if ${PORT_OPTIONS:MENIGMAIL}
MASTER_SITES+=	https://www.enigmail.net/download/source/:enigmail
DISTFILES+=	${EM_DISTFILE}:enigmail
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
EM_DISTNAME=	enigmail-${EM_VERSION}
EM_DISTFILE=	${EM_DISTNAME}.tar.gz
EM_XPI_FILE=	${WRKSRC}/mailnews/extensions/enigmail/build/${EM_DISTNAME}-${OPSYS:tl}-${ARCH:S/amd64/x86_64/:S/i386/x86/}-gcc3.xpi
EM_ORIG_ID=	{847b3a00-7ab1-11d4-8f02-006008948af5}
EM_ID=		${PORTNAME}@mozilla-enigmail.org
EM_ID_RFILES=	${XPI_LIBDIR}/${EM_ID}/install.rdf \
		${XPI_LIBDIR}/${EM_ID}/components/enigmail.js \
		${XPI_LIBDIR}/${EM_ID}/modules/enigmailCommon.jsm
.endif

.if ${PORT_OPTIONS:MLIGHTNING}
MOZ_OPTIONS+=	--enable-calendar
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=calendar
LIGHTNING_DIR=	share/lightning
XPI_FILE=	${MOZ_OBJDIR}/mozilla/dist/xpi-stage/lightning-${L_VERSION}.en-US.${OPSYS:tl}${OSREL}-${ARCH:S/amd64/x86_64/}.xpi
XPI_ORIG_ID=	{e2fda1a4-762b-4020-b5ad-a41df1933103}
XPI_ID=		lightning@thunderbird.mozilla.org
.else
MOZ_OPTIONS+=	--disable-calendar
.endif

post-extract:
	@${SED} -e 's|@PORTNAME_ICON@|${PORTNAME_ICON}|;s|@MOZILLA@|${MOZILLA}|' \
		<${FILESDIR}/thunderbird.desktop.in >${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop
.if ${PORT_OPTIONS:MENIGMAIL}
	@${TAR} -xf ${_DISTDIR}/${EM_DISTFILE} \
		-C ${WRKSRC}/mailnews/extensions
.endif

post-patch:
	@${REINPLACE_CMD} -e '/MOZPNG/s/=[0-9]*/=10511/' \
		${MOZSRC}/configure.in ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/mail/app/nsMailApp.cpp
.if ${PORT_OPTIONS:MENIGMAIL}
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},' \
		${WRKSRC}/mailnews/extensions/enigmail/util/fixlang.pl \
		${WRKSRC}/mailnews/extensions/enigmail/util/make-lang-xpi.pl
	@${REINPLACE_CMD} -e '/^xpi/s/$$/ all/' \
		-e '/^all/s/ xpi//' \
		-e '/^XPI_MODULE_VERS/s/= .*/= ${EM_VERSION}/' \
		${WRKSRC}/mailnews/extensions/enigmail/Makefile
	@${REINPLACE_CMD} -e '/em:version/s,>[^<]*<,>${EM_VERSION}<,' \
		-e '/em:maxVersion/s/pre//' \
		${WRKSRC}/mailnews/extensions/enigmail/package/install.rdf
.endif

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

.if ${PORT_OPTIONS:MENIGMAIL}
post-configure:
	cd ${WRKSRC}/mailnews/extensions/enigmail/ && \
		${SETENV} ${MAKE_ENV} ./configure

post-build:
	${DO_MAKE_BUILD:S/${MAKEFILE}/Makefile/} all xpi \
		-C ${WRKSRC}/mailnews/extensions/enigmail
.endif

port-pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/defaults

post-install:
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${LN} -sf ${PORTNAME_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME_ICON}
.if ${PORT_OPTIONS:MLIGHTNING}
	@${MKDIR} ${STAGEDIR}${XPI_LIBDIR}/${XPI_ID} ${STAGEDIR}${XPI_LIBDIR}/symlinks/thunderbird
	@(cd ${STAGEDIR}${XPI_LIBDIR}/${XPI_ID}; ${TAR} -xf ${XPI_FILE})
	@${REINPLACE_CMD} -i "" "s/${XPI_ORIG_ID}/${XPI_ID}/" ${STAGEDIR}${XPI_LIBDIR}/${XPI_ID}/install.rdf
	@${CHMOD} -R a+rX,go-w ${STAGEDIR}${XPI_LIBDIR}/${XPI_ID}
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${STAGEDIR}${XPI_LIBDIR}/symlinks/thunderbird 2>/dev/null || true
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${XPI_ID} ${LOCALBASE}/lib/thunderbird/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/thunderbird/extensions/${XPI_ID}' >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MENIGMAIL}
	@${MKDIR} ${STAGEDIR}${XPI_LIBDIR}/${EM_ID} ${STAGEDIR}${XPI_LIBDIR}/symlinks/${PORTNAME}
	@(cd ${STAGEDIR}${XPI_LIBDIR}/${EM_ID}; ${TAR} -xf ${EM_XPI_FILE})
	@${REINPLACE_CMD} -i "" "s/${EM_ORIG_ID}/${EM_ID}/" ${EM_ID_RFILES:S/^/${STAGEDIR}/}
	@${CHMOD} -R a+rX,go-w ${STAGEDIR}${XPI_LIBDIR}/${EM_ID}
	@${LN} -sf ${XPI_LIBDIR}/${EM_ID} ${STAGEDIR}${XPI_LIBDIR}/symlinks/${PORTNAME} 2>/dev/null || true
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${EM_ID} ${LOCALBASE}/lib/${PORTNAME}/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/${PORTNAME}/extensions/${EM_ID}' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
