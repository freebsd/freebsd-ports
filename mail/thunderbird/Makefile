# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird
DISTVERSION=	24.1.0
CATEGORIES=	mail ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		https://ftp.mozilla.org/pub/mozilla.org/${PORTNAME}/candidates/${DISTVERSION}-candidates/build1/source/
DISTFILES=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

BUILD_DEPENDS=	nspr>=4.10:${PORTSDIR}/devel/nspr \
		nss>=3.15:${PORTSDIR}/security/nss \
		sqlite3>=3.7.17:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		cairo>=1.10.2_1,1:${PORTSDIR}/graphics/cairo \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

EM_VERSION=	1.6
L_VERSION=	2.6.2

SSP_UNSAFE=	yes
USE_AUTOTOOLS=	autoconf213:env
USE_PYTHON_BUILD=-2.7
OBJDIR_BUILD=	# in-tree build broken after bug 789837
USE_GECKO=	gecko
USE_MOZILLA=	# empty

WANT_GNOME=	yes
USE_QT4=	# empty
QT_NONSTANDARD=	yes
ALL_TARGET=	default
USE_BZIP2=	yes
USE_GL=		gl
USE_DOS2UNIX=	mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp

MOZ_PROTOCOLS=	http,ftp,file,viewsource,res,data,wyciwyg,websocket
MOZ_OPTIONS=	--program-transform-name='s/thunderbird/${MOZILLA}/' \
	--enable-single-profile --disable-profilesharing \
	--enable-application=mail --enable-official-branding
MOZ_MK_OPTIONS=	MOZ_MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1
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

NO_STAGE=	yes
.include "${.CURDIR}/../../www/firefox/Makefile.options"

OPTIONS_DEFAULT:=${OPTIONS_DEFAULT:S/GSTREAMER//}

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/comm-esr24
MOZSRC:=	${WRKSRC}/mozilla

XPI_LIBDIR=	${PREFIX}/lib/xpi

# libprldap60.so: Undefined symbol "PR_GetCurrentThread"
.if ${ARCH} == i386
USE_GCC?=	yes
.endif

.if ${PORT_OPTIONS:MENIGMAIL}
MASTER_SITES+=	https://www.enigmail.net/download/source/:enigmail
DISTFILES+=	${EM_DISTFILE}:enigmail
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
EM_DISTNAME=	enigmail-${EM_VERSION}
EM_DISTFILE=	${EM_DISTNAME}.tar.gz
EM_XPI_FILE=	${MOZ_OBJDIR}/mozilla/dist/bin/${EM_DISTNAME}-${OPSYS:L}-${ARCH:S/amd64/x86_64/}.xpi
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
XPI_FILE=	${MOZ_OBJDIR}/mozilla/dist/xpi-stage/lightning-${L_VERSION}.en-US.${OPSYS:L}${OSREL}-${ARCH:S/amd64/x86_64/}.xpi
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
		${WRKSRC}/mailnews/extensions/enigmail/makemake
	@${REINPLACE_CMD} -e '/^xpi/s/$$/ all/' \
		-e '/^XPI_MODULE_VERS/s/= .*/= ${EM_VERSION}/' \
		${WRKSRC}/mailnews/extensions/enigmail/Makefile.in
	@${REINPLACE_CMD} -e '/em:version/s,>[^<]*<,>${EM_VERSION}<,' \
		-e '/em:maxVersion/s/pre//' \
		${WRKSRC}/mailnews/extensions/enigmail/package/install.rdf
.endif

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

.if ${PORT_OPTIONS:MENIGMAIL}
post-build:
	cd ${WRKSRC}/mailnews/extensions/enigmail && \
		./makemake -r -o ${MOZ_OBJDIR}
	${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER} all xpi \
		-C ${MOZ_OBJDIR}/mailnews/extensions/enigmail
.endif

port-pre-install:
	${MKDIR} ${FAKEDIR}/lib/${PORTNAME}/defaults

pre-install:
	@${ECHO_CMD} 'share/applications/${PORTNAME}.desktop' >> ${PLIST}
	@${ECHO_CMD} 'share/pixmaps/${PORTNAME_ICON}' >> ${PLIST}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop ${PREFIX}/share/applications
	${LN} -sf ${PORTNAME_ICON_SRC} ${PREFIX}/share/pixmaps/${PORTNAME_ICON}
.if ${PORT_OPTIONS:MLIGHTNING}
	@${MKDIR} ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/thunderbird
	@(cd ${XPI_LIBDIR}/${XPI_ID}; ${TAR} -xf ${XPI_FILE})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${XPI_ID}
	@${REINPLACE_CMD} -i "" "s/${XPI_ORIG_ID}/${XPI_ID}/" ${XPI_LIBDIR}/${XPI_ID}/install.rdf
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${XPI_ID}
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${LOCALBASE}/lib/thunderbird/extensions 2>/dev/null || true
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/thunderbird 2>/dev/null || true
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} 'lib/xpi/symlinks/thunderbird/${XPI_ID}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${XPI_ID} ${LOCALBASE}/lib/thunderbird/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/thunderbird/extensions/${XPI_ID}' >> ${TMPPLIST}
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm lib/xpi/,p' >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MENIGMAIL}
	@${MKDIR} ${XPI_LIBDIR}/${EM_ID} ${XPI_LIBDIR}/symlinks/${PORTNAME}
	@(cd ${XPI_LIBDIR}/${EM_ID}; ${TAR} -xf ${EM_XPI_FILE})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${EM_ID}
	@${REINPLACE_CMD} -i "" "s/${EM_ORIG_ID}/${EM_ID}/" ${EM_ID_RFILES}
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${EM_ID}
	@${LN} -sf ${XPI_LIBDIR}/${EM_ID} ${LOCALBASE}/lib/${PORTNAME}/extensions 2>/dev/null || true
	@${LN} -sf ${XPI_LIBDIR}/${EM_ID} ${XPI_LIBDIR}/symlinks/${PORTNAME} 2>/dev/null || true
	@(cd ${XPI_LIBDIR}; ${FIND} ${EM_ID} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} 'lib/xpi/symlinks/${PORTNAME}/${EM_ID}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${EM_ID} ${LOCALBASE}/lib/${PORTNAME}/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/${PORTNAME}/extensions/${EM_ID}' >> ${TMPPLIST}
	@(cd ${XPI_LIBDIR}; ${FIND} ${EM_ID} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm lib/xpi/,p' >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MLIGHTNING} || ${PORT_OPTIONS:MENIGMAIL}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks/${PORTNAME} 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi 2>/dev/null || true' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
