# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	1.0.2
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/1.0.2/source
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
FAKEDIR=	${WRKDIR}/fake
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
ESD_LIB=	libesd.so.2
PLIST=		${WRKDIR}/plist
PLUGINSDIR=	${PREFIX}/lib/browser_plugins
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libidl gnomehier desktopfileutils
USE_ICONV=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mozilla
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/* \
			--exclude */macbuild/*\
			--exclude */package/* \
			--exclude .cvsignore \
			--exclude makefile.win \
			--exclude MANIFEST

FIREFOX=	${PORTNAME}
FF_VER=		${PORTVERSION}

FIREFOX_ICON=	firefox.png
FIREFOX_ICON_SRC=${WRKSRC}/other-licenses/branding/firefox/content/alert-exclam.png

PKGCONFIG_FILES=firefox-gtkmozembed firefox-js firefox-xpcom \
		firefox-nspr firefox-nss firefox-plugin

JPI_LIST?=\
	${LOCALBASE}/jdk1.4.2/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.4.1/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/diablo-jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so

SYSTEM_PREFS=		${FAKEDIR}/lib/${FIREFOX}-${FF_VER}/defaults/pref/firefox.js
SCRIPTS_DIR=		${FAKEDIR}/lib/${FIREFOX}-${FF_VER}
MOZ_PIS_SCRIPTS=	S50cleanhome
MOZ_PIS_DIR=		${SCRIPTS_DIR}/init.d

OPTIONS=	DEBUG "Build a debugging image" off \
		LOGGING "Enable additional log messages" off \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off \
		XFT "Enable support for anti-aliased fonts" on \
		SMB "Enable smb:// URI support using gnomevfs" off \
		NEWTAB "Open external links in a new tab" on

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

.if defined(WITH_SMB)
USE_GNOME+=	gnomevfs2
CONFIGURE_ENV+=	WITH_SMB=yes
.endif # defined(WITH_SMB)

CPPFLAGS+=		-I${X11BASE}/include -I${LOCALBASE}/include
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			${PTHREAD_LIBS}

EXTRA_SCRIPTS=		${PORTNAME}.rb

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	"core dumps on alpha during post-build"
.endif

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

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
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/firefox.desktop

post-patch:
	@${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${FIREFOX}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${MASTERDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${FIREFOX}|g' \
		< ${MASTERDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
.for ii in ${EXTRA_SCRIPTS}
	@${SED} -e 's|%%MOZILLA%%|${FIREFOX}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${FILESDIR}/${ii} > ${WRKDIR}/${ii}
.endfor
.for ii in ${MOZ_PIS_SCRIPTS}
	@${SED} -e 's|%%MOZILLA%%|${FIREFOX}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${FILESDIR}/moz_pis_${ii} > ${WRKDIR}/moz_pis_${ii}
.endfor
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/nsprpub/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/nsprpub/config/config.mk \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${REINPLACE_CMD} -e 's|libesd\.so\.\d+|${ESD_LIB}|g' \
		${WRKSRC}/widget/src/gtk2/nsSound.cpp
	@${REINPLACE_CMD} -E -e 's|libcups\.so\.[0-9]+|libcups.no|g' \
		${WRKSRC}/gfx/src/gtk/nsDeviceContextSpecG.cpp
.for ii in modules/libpref/src/init extensions/sroaming/resources/content/prefs \
	embedding/minimo
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/' \
		${WRKSRC}/${ii}/all.js
.endfor

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^bind[0-9]*-base-[0-9]'`" ]; then \
		${ECHO_CMD} "${PKGNAME}: bind installed with PORT_REPLACES_BASE_BIND causes build problems."; \
		${FALSE}; \
	fi

pre-install:
	@${RM} -rf ${FAKEDIR} ${PLIST}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} install
	@${MKDIR} ${SCRIPTS_DIR}
	@${MKDIR} ${MOZ_PIS_DIR}
	${ECHO_CMD} 'share/gnome/pixmaps/${FIREFOX_ICON}' >> ${PLIST}
	${ECHO_CMD} 'share/gnome/applications/firefox.desktop' >> ${PLIST}
	${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g; \
		s|${FIREFOX}-${FF_VER}|${FIREFOX}|' \
		${FAKEDIR}/bin/firefox \
		${FAKEDIR}/bin/firefox-config
	for i in ${EXTRA_SCRIPTS}; do \
		${ECHO_CMD} bin/$${i} >> ${PLIST}; \
	done
	${ECHO_CMD} bin/firefox >> ${PLIST}
	${ECHO_CMD} bin/firefox-config >> ${PLIST}
.for ii in ${MOZ_PIS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/moz_pis_${ii} ${MOZ_PIS_DIR}/${ii}
.endfor
.if !defined(WITHOUT_NEWTAB)
	${ECHO_CMD} >> ${SYSTEM_PREFS}
	${ECHO_CMD} "// Open external links in new tab" >> ${SYSTEM_PREFS}
	${ECHO_CMD} "pref(\"browser.link.open_external\", 3);" \
		>> ${SYSTEM_PREFS}
.endif # !defined(WITHOUT_NEWTAB)
	cd ${FAKEDIR}/lib/${FIREFOX}-${FF_VER} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|lib/${FIREFOX}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/${FIREFOX}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/firefox >> ${PLIST}
	for pcfile in ${PKGCONFIG_FILES}; do \
		${REINPLACE_CMD} -e 's|${FIREFOX}-${FF_VER}|${FIREFOX}|g; \
			s|${FAKEDIR}|${PREFIX}|' \
			${FAKEDIR}/lib/pkgconfig/$${pcfile}.pc ; \
		${ECHO_CMD} libdata/pkgconfig/$${pcfile}.pc >> ${PLIST} ; \
	done
	cd ${FAKEDIR}/include/${FIREFOX}-${FF_VER} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/${FIREFOX}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm include/${FIREFOX}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${FIREFOX} >> ${PLIST}
	${ECHO_CMD} lib/browser_plugins/.${PORTNAME}.keep >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/browser_plugins 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${FIREFOX}
	${CHMOD} 755 ${PREFIX}/lib/${FIREFOX}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/firefox ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/firefox-config ${PREFIX}/bin
	if [ ! -d ${PREFIX}/lib/browser_plugins ]; then \
		${MKDIR} ${PREFIX}/lib/browser_plugins ; \
	fi
	${TOUCH} -f ${PREFIX}/lib/browser_plugins/.${PORTNAME}.keep
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
				${LN} -sf $${jpi} \
					${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ; \
				break; \
			fi; \
		done; \
	fi
	for pcfile in ${PKGCONFIG_FILES}; do \
		${INSTALL_DATA} ${FAKEDIR}/lib/pkgconfig/$${pcfile}.pc \
			${PREFIX}/libdata/pkgconfig/$${pcfile}.pc ; \
	done
	-${RM} -fr ${PREFIX}/include/${FIREFOX}
	${MKDIR} ${PREFIX}/include/${FIREFOX}
	${CHMOD} 755 ${PREFIX}/include/${FIREFOX}
	cd ${FAKEDIR}/include/${FIREFOX}-${FF_VER} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${FIREFOX}
	cd ${FAKEDIR}/lib/${FIREFOX}-${FF_VER} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${FIREFOX}

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
.for i in ${EXTRA_SCRIPTS}
	${INSTALL_SCRIPT} ${FILESDIR}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${FIREFOX_ICON_SRC} ${PREFIX}/share/gnome/pixmaps/${FIREFOX_ICON}
	${INSTALL_DATA} ${WRKDIR}/firefox.desktop ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/other-licenses/branding/firefox/default.xpm \
		${PREFIX}/lib/${FIREFOX}/chrome/icons/default/default.xpm
	@-update-desktop-database

.include <bsd.port.post.mk>
