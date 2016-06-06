# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird
DISTVERSION=	45.1.1
CATEGORIES=	mail news net-im ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}-candidates/build1/source
DISTFILES=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

BUILD_DEPENDS=	nspr>=4.12:devel/nspr \
		nss>=3.21.1:security/nss \
		libevent2>=2.0.21_2:devel/libevent2 \
		soundtouch>=1.9.0:audio/soundtouch \
		harfbuzz>=1.1.0:print/harfbuzz \
		graphite2>=1.3.7:graphics/graphite2 \
		png>=1.6.19:graphics/png \
		libvorbis>=1.3.5,3:audio/libvorbis \
		libvpx>=1.5.0:multimedia/libvpx \
		sqlite3>=3.9.1:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf-2.13:devel/autoconf213 \
		yasm:devel/yasm \
		zip:archivers/zip \
		unzip:archivers/unzip

LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

EM_VERSION=	1.9.3
L_VERSION=	4.7.1.1

SSP_UNSAFE=	yes
USE_GECKO=	gecko
USE_MOZILLA=	# empty

USE_QT5=	# empty
QT_NONSTANDARD=	yes
USE_GL=		gl
USES=		tar:xz

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

OPTIONS_EXCLUDE=GSTREAMER LOGGING
OPTIONS_DEFINE=	ENIGMAIL LIGHTNING RUST
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=BUNDLED_CAIRO CANBERRA ENIGMAIL GTK2 LIGHTNING

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/${PORTNAME}-${DISTVERSION}
MOZSRC:=	${WRKSRC}/mozilla

XPI_LIBDIR=	${PREFIX}/lib/xpi

.if ${PORT_OPTIONS:MENIGMAIL}
MASTER_SITES+=	https://www.enigmail.net/download/source/:enigmail
DISTFILES+=	${EM_DISTFILE}:enigmail
RUN_DEPENDS+=	gpg2:security/gnupg
EM_DISTNAME=	enigmail-${EM_VERSION}
EM_DISTFILE=	${EM_DISTNAME}.tar.gz
EM_XPI_FILE=	${WRKSRC}/mailnews/extensions/enigmail/build/${EM_DISTNAME}.xpi
EM_ORIG_ID=	{847b3a00-7ab1-11d4-8f02-006008948af5}
EM_ID=		${PORTNAME}@mozilla-enigmail.org
EM_ID_RFILES=	${XPI_LIBDIR}/${EM_ID}/install.rdf \
		${XPI_LIBDIR}/${EM_ID}/components/enigmail.js \
		${XPI_LIBDIR}/${EM_ID}/modules/app.jsm
.endif

.if ${PORT_OPTIONS:MLIGHTNING}
MOZ_OPTIONS+=	--enable-calendar
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=calendar
LIGHTNING_DIR=	share/lightning
XPI_FILE=	${MOZ_OBJDIR}/dist/xpi-stage/lightning-${L_VERSION}.en-US.${OPSYS:tl}${OSREL}-${ARCH:S/amd64/x86_64/}.xpi
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
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${MOZSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${MOZSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

.if ${PORT_OPTIONS:MENIGMAIL}
post-configure:
	cd ${WRKSRC}/mailnews/extensions/enigmail/ && \
		${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ./configure

post-build:
	${DO_MAKE_BUILD:N-j*:S,${MAKEFILE},Makefile,} all xpi \
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
