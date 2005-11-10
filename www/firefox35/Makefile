# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/firefox-devel/Makefile,v 1.23 2005/11/02 23:41:52 marcus Exp $
#

PORTNAME=	firefox
DISTVERSION=	1.5rc2
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${DISTVERSION}/source/
PKGNAMESUFFIX=	${FF_SUFX}
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		Xft.2:${PORTSDIR}/x11-fonts/libXft
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	Xvfb:${X_VFBSERVER_PORT}

ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
FAKEDIR=	${WRKDIR}/fake
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
PLIST=		${WRKDIR}/plist
PLUGINSDIR=	${PREFIX}/lib/browser_plugins
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libidl desktopfileutils
USE_ICONV=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
USE_GCC=	3.4+
WRKSRC=		${WRKDIR}/mozilla
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
KRB5_HOME?=	/usr

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/* \
			--exclude */macbuild/*\
			--exclude */package/* \
			--exclude .cvsignore \
			--exclude makefile.win \
			--exclude MANIFEST

FIREFOX=	${PORTNAME}
FF_SUFX=	-devel
FF=		${FIREFOX}${FF_SUFX}
FF_VER=		1.5
#FF_VER=	${PORTVERSION}

FIREFOX_ICON=		${FF}.xpm
FIREFOX_ICON_SRC=	${PREFIX}/lib/${FF}/icons/default.xpm

PKGCONFIG_FILES=firefox-gtkmozembed firefox-js firefox-xpcom \
		firefox-nspr firefox-nss firefox-plugin

JPI_LIST?=\
	${LOCALBASE}/jdk1.5.0/jre/plugin/${ARCH}/ns7/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.4.2/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so

SYSTEM_PREFS=		${FAKEDIR}/lib/${FF}/defaults/pref/firefox.js
SCRIPTS_DIR=		${FAKEDIR}/lib/${FF}
MOZ_PIS_SCRIPTS=	S50cleanhome
MOZ_PIS_DIR=		${SCRIPTS_DIR}/init.d
CPPFLAGS+=	-I${X11BASE}/include -I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	-L${X11BASE}/lib
LIBS+=		${PTHREAD_LIBS}

OPTIONS=	DEBUG "Build a debugging image" off \
		LOGGING "Enable additional log messages" off \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off \
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

.if defined(WITH_SMB)
USE_GNOME+=	gnomevfs2
CONFIGURE_ENV+=	WITH_SMB=yes
.endif # defined(WITH_SMB)

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	core dumps on alpha during post-build
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
		-e 's|@KRB5_HOME@|${KRB5_HOME}|'		\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${FF}.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|%%FIREFOX%%|${FF}|' \
		${WRKSRC}/config/autoconf.mk.in
	@${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${FF}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${MASTERDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's|%%MOZDIR%%|${PREFIX}/lib/${FF}|g' \
		< ${MASTERDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
.for ii in ${MOZ_PIS_SCRIPTS}
	@${SED} -e 's|%%MOZILLA%%|${FF}|g ; \
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
	@${REINPLACE_CMD} -E -e 's|libesd\.so\.[0-9]+|libesd.so|g' \
		${WRKSRC}/widget/src/gtk2/nsSound.cpp
	@${REINPLACE_CMD} -E -e 's|libcups\.so\.[0-9]+|libcups.so|g' \
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
		Makefile ${MAKE_ARGS} ${INSTALL_TARGET}
	@${MKDIR} ${SCRIPTS_DIR}
	@${MKDIR} ${MOZ_PIS_DIR}
	@${RM} -rf ${FAKEDIR}/lib/${FF}/extensions
	${ECHO_CMD} 'share/applications/${FF}.desktop' >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${FIREFOX_ICON}' >> ${PLIST}
	${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g; \
		s|${FIREFOX}|${FF}|; \
		s|-devel||; \
		s|$${progbase}-bin|${FIREFOX}-bin|' \
		${FAKEDIR}/bin/firefox \
		${FAKEDIR}/bin/firefox-config
	${ECHO_CMD} bin/${FF} >> ${PLIST}
	${ECHO_CMD} bin/${FF}-config >> ${PLIST}
.for ii in ${MOZ_PIS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/moz_pis_${ii} ${MOZ_PIS_DIR}/${ii}
.endfor
.if !defined(WITHOUT_NEWTAB)
	${ECHO_CMD} >> ${SYSTEM_PREFS}
	${ECHO_CMD} "// Open external links in new tab" >> ${SYSTEM_PREFS}
	${ECHO_CMD} "pref(\"browser.link.open_external\", 3);" \
		>> ${SYSTEM_PREFS}
.endif # !defined(WITHOUT_NEWTAB)
	cd ${FAKEDIR}/lib/${FF} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|lib/${FF}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/${FF}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${FF} >> ${PLIST}
	for pcfile in ${PKGCONFIG_FILES}; do \
		${REINPLACE_CMD} -e 's|${FF}|${FF}|g; \
			s|${FAKEDIR}|${PREFIX}|' \
			${FAKEDIR}/lib/pkgconfig/$${pcfile}.pc ; \
		${ECHO_CMD} libdata/pkgconfig/$${pcfile}${FF_SUFX}.pc >> ${PLIST} ; \
	done
	cd ${FAKEDIR}/include/${FF} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/${FF}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm include/${FF}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${FF} >> ${PLIST}
	${ECHO_CMD} lib/browser_plugins/.${FF}.keep >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/browser_plugins 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
	cd ${FAKEDIR}/share/idl/${FIREFOX}-${FF_VER} \
		&& ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:share/idl/${FF}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm share/idl/${FF}/:' >> ${PLIST}
		${ECHO_CMD} "@dirrm share/idl/${FF}" >> ${PLIST}
		${ECHO_CMD} "@unexec ${RMDIR} %D/share/idl 2>/dev/null || true" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${FF}
	${CHMOD} 755 ${PREFIX}/lib/${FF}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/firefox ${PREFIX}/bin/${FF}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/firefox-config ${PREFIX}/bin/${FF}-config
	${MKDIR} ${PREFIX}/lib/browser_plugins
	${TOUCH} -f ${PREFIX}/lib/browser_plugins/.${FF}.keep
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
			${PREFIX}/libdata/pkgconfig/$${pcfile}${FF_SUFX}.pc ; \
	done
	-${RM} -fr ${PREFIX}/include/${FF}
	${MKDIR} ${PREFIX}/include/${FF}
	${CHMOD} 755 ${PREFIX}/include/${FF}
	cd ${FAKEDIR}/include/${FF} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${FF}
	cd ${FAKEDIR}/lib/${FF} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${FF}
	${MKDIR} ${PREFIX}/share/idl/${FF}
	cd ${FAKEDIR}/share/idl/${FIREFOX}-${FF_VER} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/idl/${FF}

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${FF}.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${FF}/chrome/icons/default
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/lib/${FF}/chrome/icons/default/default.xpm
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/share/pixmaps/${FIREFOX_ICON}
	@-update-desktop-database

.include <bsd.port.post.mk>
