# New ports collection makefile for:	mozilla-thunderbird
# Date created:			4 September 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/mail/thunderbird/Makefile,v 1.11 2005/08/20 20:56:53 mezz Exp $
#

PORTNAME=	thunderbird
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTVERSION}/source
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg	\
		nspr4:${PORTSDIR}/devel/nspr	\
		png:${PORTSDIR}/graphics/png	\
		nss3:${PORTSDIR}/security/nss
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
FAKEDIR=	${WRKDIR}/fake
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
ESD_LIB=	libesd.so.2
PLIST=		${WRKDIR}/plist
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libidl
USE_ICONV=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mozilla
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/* \
			--exclude */macbuild/*\
			--exclude */nsprpub/*\
			--exclude */package/* \
			--exclude */zlib/ \
			--exclude mozilla/modules/libimg/png \
			--exclude mozilla/jpeg \
			--exclude mozilla/dbm \
			--exclude mozilla/js/src/fdlibm \
			--exclude mozilla/security/nss	\
			--exclude mozilla/gc/boehm	\
			--exclude .cvsignore \
			--exclude makefile.win \
			--exclude MANIFEST

PORTNAME_ICON=	${PREFIX}/lib/${PORTNAME}/chrome/icons/default/default.xpm

PKGCONFIG_FILES=${PORTNAME}-gtkmozembed ${PORTNAME}-js ${PORTNAME}-xpcom \
		${PORTNAME}-plugin

SYSTEM_PREFS=	${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults/pref/${PORTNAME}.js
SCRIPTS_DIR=	${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION}
MOZ_PIS_SCRIPTS=S50cleanhome
MOZ_PIS_DIR=	${SCRIPTS_DIR}/init.d

OPTIONS=	DEBUG "Build a debugging image" off \
		LOGGING "Enable additional log messages" off \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off \
		XFT "Enable support for anti-aliased fonts" on

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
WITH_LOGGING=		yes
CONFIGURE_ENV+=		WITH_DEBUG=yes
.endif # defined(WITH_DEBUG)

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS:=		-O2 -fno-strict-aliasing ${CFLAGS:N-O*}
.else
CFLAGS:=		-O ${CFLAGS:N-O*:N-m*}
CONFIGURE_ENV+=		WITH_OPTIMIZE=-O
.endif # defined(WITH_OPTIMIZED_CFLAGS)

.if defined(WITH_LOGGING)
CONFIGURE_ENV+=	WITH_LOGGING=yes
.endif # defined(WITH_LOGGING)

.if defined(WITHOUT_XFT)
CONFIGURE_ENV+=	WITHOUT_XFT=yes
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
.endif # !defined(WITHOUT_XFT)

CPPFLAGS+=		-I${X11BASE}/include
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			${PTHREAD_LIBS}

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	core dumps at runtime
.endif # ${ARCH} == "alpha" && ${OSVERSION} < 500035

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif # ${PERL_LEVEL} < 500600

pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "Extracting source (this takes a while) ..."
	@${ECHO_MSG}

post-extract::
	@${SED} -e 's|@CPPFLAGS@|${CPPFLAGS}|'		\
		-e 's|@CFLAGS@|${CFLAGS}|'		\
		-e 's|@LDFLAGS@|${LDFLAGS}|'		\
		-e 's|@LIBS@|${LIBS}|'			\
		-e 's|@X11BASE@|${X11BASE}|'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|'	\
		-e 's|@FAKEDIR@|${FAKEDIR}|'		\
		-e 's|@PERL@|${PERL5}|'			\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig
	@${SED} -e 's|@PORTNAME_ICON@|${PORTNAME_ICON}|' \
		<${FILESDIR}/${PORTNAME}.desktop.in >${WRKDIR}/${PORTNAME}.desktop

post-patch:
	@${REINPLACE_CMD} -e  's/%{idldir}/%idldir%/g ; \
		s|"%FULL_NSPR_CFLAGS%"|`nspr-config --cflags`|g ; \
		s|"%FULL_NSPR_LIBS%"|`nspr-config --libs`|g' \
			${WRKSRC}/build/unix/mozilla-config.in
	@${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${PORTNAME}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${MASTERDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${PORTNAME}|g' \
		< ${MASTERDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
.for ii in ${MOZ_PIS_SCRIPTS}
	@${SED} -e 's|%%MOZILLA%%|${PORTNAME}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${FILESDIR}/moz_pis_${ii} > ${WRKDIR}/moz_pis_${ii}
.endfor
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${REINPLACE_CMD} -e 's|libesd\.so\.\d+|${ESD_LIB}|g' \
		${WRKSRC}/widget/src/gtk2/nsSound.cpp
	@${REINPLACE_CMD} -E -e 's|libcups\.so\.[0-9]+|libcups.so|g' \
		${WRKSRC}/gfx/src/gtk/nsDeviceContextSpecG.cpp
	@${REINPLACE_CMD} -e 's|/usr/local/netscape|${LOCALBASE}|g' \
		-e 's|/usr/local/lib/netscape|${LOCALBASE}/lib|g' \
		${WRKSRC}/xpcom/*/SpecialSystemDirectory.cpp
	@${FIND} ${WRKSRC} -name all.js | ${XARGS} ${REINPLACE_CMD} -e \
		'/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/'
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^bind[0-9]*-base-[0-9]'`" ]; then \
		${ECHO_CMD} "${PKGNAME}: bind installed with PORT_REPLACES_BASE_BIND causes build problems."; \
		${FALSE}; \
	fi

pre-install:
	@${RM} -rf ${FAKEDIR} ${PLIST}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} ${INSTALL_TARGET}
	@${MKDIR} ${SCRIPTS_DIR}
	@${MKDIR} ${MOZ_PIS_DIR}
	${ECHO_CMD} 'share/applications/${PORTNAME}.desktop' >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g; \
		s|${PORTNAME}-${PORTVERSION}|${PORTNAME}|' \
		${FAKEDIR}/bin/${PORTNAME} \
		${FAKEDIR}/bin/${PORTNAME}-config
	${ECHO_CMD} bin/${PORTNAME} >> ${PLIST}
	${ECHO_CMD} bin/${PORTNAME}-config >> ${PLIST}
.for ii in ${MOZ_PIS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/moz_pis_${ii} ${MOZ_PIS_DIR}/${ii}
.endfor
	@${MKDIR} ${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults
	@${CP} -RL ${WRKSRC}/dist/bin/defaults/isp \
		${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults
	cd ${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|lib/${PORTNAME}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/${PORTNAME}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${PORTNAME} >> ${PLIST}
	for pcfile in ${PKGCONFIG_FILES}; do \
		${REINPLACE_CMD} -e 's|${PORTNAME}-${PORTVERSION}|${PORTNAME}|g; \
			s|${FAKEDIR}|${PREFIX}|g ; \
			s|${PORTNAME}-nspr = ${PORTVERSION}|nspr >= 4.6.0|g' \
			${FAKEDIR}/lib/pkgconfig/$${pcfile}.pc ; \
		${ECHO_CMD} libdata/pkgconfig/$${pcfile}.pc >> ${PLIST} ; \
	done
	cd ${FAKEDIR}/include/${PORTNAME}-${PORTVERSION} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/${PORTNAME}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm include/${PORTNAME}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${PORTNAME} >> ${PLIST}
	cd ${FAKEDIR}/share/idl/${PORTNAME}-${PORTVERSION} \
		&& ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:share/idl/${PORTNAME}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm share/idl/${PORTNAME}/:' >> ${PLIST}
		${ECHO_CMD} "@dirrm share/idl/${PORTNAME}" >> ${PLIST}
		${ECHO_CMD} "@unexec ${RMDIR} %D/share/idl 2>/dev/null || true" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${CHMOD} 755 ${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/${PORTNAME}-config ${PREFIX}/bin
	for pcfile in ${PKGCONFIG_FILES}; do \
		${INSTALL_DATA} ${FAKEDIR}/lib/pkgconfig/$${pcfile}.pc \
			${PREFIX}/libdata/pkgconfig/$${pcfile}.pc ; \
	done
	-${RM} -fr ${PREFIX}/include/${PORTNAME}
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	${CHMOD} 755 ${PREFIX}/include/${PORTNAME}
	cd ${FAKEDIR}/include/${PORTNAME}-${PORTVERSION} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${PORTNAME}
	cd ${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${PREFIX}/share/idl/${PORTNAME}
	cd ${FAKEDIR}/share/idl/${PORTNAME}-${PORTVERSION} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/idl/${PORTNAME}

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/other-licenses/branding/${PORTNAME}/default.xpm \
		${PREFIX}/lib/${PORTNAME}/chrome/icons/default/default.xpm

.include <bsd.port.post.mk>
