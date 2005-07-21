# New ports collection makefile for:	mozilla-thunderbird
# Date created:			4 September 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thunderbird
PORTVERSION=	1.0.6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	thunderbird/releases/${PORTVERSION}/source
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_X_PREFIX=	yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
NO_MTREE=	yes
PLIST=		${WRKDIR}/plist
ALL_TARGET=	default
USE_GNOME=	gtk20 libidl
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
FAKEDIR=	${WRKDIR}/fake

NO_MTREE=		yes
WRKSRC=			${WRKDIR}/mozilla
LOCAL_SUBDIR=		lib/${PORTNAME}
LOCAL_PREFIX=		${PREFIX}/${LOCAL_SUBDIR}
ESD_LIB=		libesd.so.2

THUNDERBIRD=		${PORTNAME}
THUNDERBIRD_ICON=	${LOCAL_PREFIX}/lib/${PORTNAME}-${PORTVERSION}/chrome/icons/default/default.xpm
MOZ_PIS_SCRIPTS=	S50cleanhome
SCRIPTS_DIR=		${FAKEDIR}/${LOCAL_SUBDIR}/lib/${PORTNAME}-${PORTVERSION}
MOZ_PIS_DIR=		${SCRIPTS_DIR}/init.d

OPTIONS=	DEBUG "Build a debugging image" off \
		LOGGING "Enable additional log messages" off \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off \
		XFT "Enable support for anti-aliased fonts" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	"core dumps at runtime"
.endif # ${ARCH} == "alpha" && ${OSVERSION} < 500035

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif # ${PERL_LEVEL} < 500600

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

pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "Extracting source (this takes a while) ..."
	@${ECHO_MSG}

post-extract::
# FAKEDIR is here so that nsinstall will install under FAKEDIR, not
# under PREFIX.  See pre-install and do-install for details.
	@${SED} -e 's|@CPPFLAGS@|${CPPFLAGS}|'			\
		-e 's|@CFLAGS@|${CFLAGS}|'			\
		-e 's|@LDFLAGS@|${LDFLAGS}|'			\
		-e 's|@LIBS@|${LIBS}|'				\
		-e 's|@X11BASE@|${X11BASE}|'			\
		-e 's|@LOCALBASE@|${LOCALBASE}|'		\
		-e 's|@PREFIX@|${FAKEDIR}/lib/thunderbird|'	\
		-e 's|@PERL@|${PERL5}|'				\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/nsprpub/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/nsprpub/configure \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${REINPLACE_CMD} -E -e 's|libesd\.so\.[0-9]+|${ESD_LIB}|g' \
		${WRKSRC}/widget/src/gtk2/nsSound.cpp
	@${REINPLACE_CMD} -E -e 's|libcups\.so\.[0-9]+|libcups.no|g' \
		${WRKSRC}/gfx/src/gtk/nsDeviceContextSpecG.cpp
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/' \
		${WRKSRC}/modules/libpref/src/init/all.js \
		${WRKSRC}/extensions/sroaming/resources/content/prefs/all.js \
		${WRKSRC}/modules/libpref/src/init/all.js
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp
	@${SED} -e 's|%%MOZDIR%%|${LOCAL_PREFIX}/lib/${PORTNAME}-${PORTVERSION}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${MASTERDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's|%%MOZDIR%%|${LOCAL_PREFIX}/lib/${PORTNAME}-${PORTVERSION}|g' \
		< ${MASTERDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SED} -e 's|@THUNDERBIRD_ICON@|${THUNDERBIRD_ICON}|' \
		< ${FILESDIR}/thunderbird.desktop.in > ${WRKDIR}/thunderbird.desktop
.for ii in ${MOZ_PIS_SCRIPTS}
	@${SED} -e 's|%%MOZILLA%%|${THUNDERBIRD}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${FILESDIR}/moz_pis_${ii} > ${WRKDIR}/moz_pis_${ii}
.endfor

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^bind[0-9]*-base-[0-9]'`" ]; then \
		${ECHO_CMD} "${PKGNAME}: bind installed with PORT_REPLACES_BASE_BIND causes build problems."; \
		${FALSE}; \
	fi

post-build:
# XXX This works around an install problem that is triggered when
# toolkit/profile/src is built after profile/src.
	@${TOUCH} -f ${WRKSRC}/profile/build/libprofile.so

pre-install:
# Overview:  the program installs itself in FAKEDIR, then a list is made of the
# files and directories in there.  This is the PLIST (packing list) for the
# package, replacing the traditional pkg-plist file.
	@${RM} -rf ${FAKEDIR} ${PLIST}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} install
	@${MKDIR} ${SCRIPTS_DIR}
	@${MKDIR} ${MOZ_PIS_DIR}
.for ii in mac win
.for jj in / .jar
	@${RM} -rf ${FAKEDIR}/lib/${PORTNAME}/lib/${PORTNAME}-${PORTVERSION}/chrome/en-${ii}${jj}
.endfor
.endfor
	@${RM} -fr ${FAKEDIR}/share/idl ${FAKEDIR}/include
.for ii in thunderbird thunderbird-config
	@${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
.for ii in ${MOZ_PIS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/moz_pis_${ii} ${MOZ_PIS_DIR}/${ii}
.endfor
	@${MKDIR} ${FAKEDIR}/${LOCAL_SUBDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults
	@${CP} -RL ${WRKSRC}/dist/bin/defaults/isp \
		${FAKEDIR}/${LOCAL_SUBDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults
	@cd ${FAKEDIR} && ${FIND} * ! -type d | ${SORT} >> ${PLIST}; \
	${FIND} * -type d -empty | ${SORT} | ${SED} -e \
		"s:^:@exec ${MKDIR} %D/:" -e "s:$$: || true:" >> ${PLIST}; \
	${FIND} * -type d -empty | ${SORT} -r | ${SED} -e \
		"s:^:@unexec ${RMDIR} %D/:" -e "s:$$: || true:" >> ${PLIST}; \
	${FIND} * -type d ! -empty | ${SORT} -r | ${SED} -e "s:^:@dirrm :" | \
		${GREP} / >> ${PLIST}
	${ECHO_CMD} 'share/applications/thunderbird.desktop' >> ${PLIST}
	${ECHO_CMD} '@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}' >> ${PLIST}

do-install:
# This is the actual installation.  First, the contents of FAKEDIR are
# just copied to PREFIX.
	cd ${FAKEDIR} && ${FIND} * | ${CPIO} -dmp --quiet ${PREFIX}

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${MKDIR} ${PREFIX}/bin
	${RM} -f ${PREFIX}/bin/thunderbird
	${LN} -s ${LOCAL_PREFIX}/bin/thunderbird \
		${PREFIX}/bin/thunderbird
	${RM} -f ${PREFIX}/bin/thunderbird-config
	${LN} -s ${LOCAL_PREFIX}/bin/thunderbird-config \
		${PREFIX}/bin/thunderbird-config
	${PERL} -pi -e 's|${FAKEDIR}|${PREFIX}|g' \
		${LOCAL_PREFIX}/bin/thunderbird \
		${LOCAL_PREFIX}/bin/thunderbird-config
	${FIND} ${LOCAL_PREFIX}/lib/pkgconfig -type f | ${XARGS} \
		${PERL} -pi -e 's|${FAKEDIR}|${PREFIX}|g'
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/thunderbird.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/other-licenses/branding/thunderbird/default.xpm \
		${LOCAL_PREFIX}/lib/${PORTNAME}-${PORTVERSION}/chrome/icons/default/default.xpm

.include <bsd.port.post.mk>
