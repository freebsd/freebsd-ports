# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME?=	mozilla
PORTVERSION=	1.3a
PORTREVISION?=	0
PORTEPOCH?=	1
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA} \
	      	${MASTER_SITE_LOCAL}:local
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION:S/.rc/rc/}/src \
		marcus/:local
DISTFILES=	${PORTNAME}-source-${PORTVERSION:S/.rc/rc/}${EXTRACT_SUFX} \
		libart_lgpl-${PORTVERSION}${EXTRACT_SUFX}:local

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}

MOZILLA?=	mozilla-devel

WITHOUT_CHATZILLA=	"Contains a buffer overflow reported at http://online.securityfocus.com/archive/1/270249"

.if defined(WITH_GTK2)
LIB_DEPENDS+=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		ORBit-2.0:${PORTSDIR}/devel/ORBit2
.else
USE_GNOME=	gtk12
.endif

.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	Xft2.2:${PORTSDIR}/x11-fonts/Xft
.if exists(${X11BASE}/lib/X11/fonts/mozilla/fonts.dir)
BROKEN=		Mozilla-devel and Xft2 render the mozilla-fonts \
	 	illegibly. Please remove the mozilla-fonts package.
.endif
.endif

.if defined(WITH_CALENDAR) && (defined(WITHOUT_MAILNEWS) || \
	defined(WITHOUT_COMPOSER))
BROKEN=	Calendar requires Composer and Mailnews support.
.endif

.if defined(WITH_CALENDAR)
LIB_DEPENDS+=	ical.0:${PORTSDIR}/devel/libical
.endif

LATEST_LINK=	${MOZILLA}
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/* \
			--exclude */macbuild/*\
			--exclude */package/* \
			--exclude .cvsignore \
			--exclude makefile.win \
			--exclude MANIFEST
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=					\
		--disable-auto-deps		\
		--enable-chrome-format=jar	\
		--disable-cpp-exceptions	\
		--disable-cpp-rtti		\
		--enable-crypto			\
		--disable-debug			\
		--enable-double-buffer		\
		--enable-mathml			\
		--disable-md			\
		--disable-pedantic		\
		--disable-plaintext-editor-only	\
		--enable-strip			\
		--enable-svg			\
		--disable-tests			\
		--disable-xterm-updates		\
		--enable-xinerama		\
		--with-system-jpeg=${LOCALBASE}	\
		--with-system-mng=${LOCALBASE}	\
		--with-system-png=${LOCALBASE}	\
		--with-pthreads

.if !defined(WITH_GTK2)
USE_GNOMENG=	yes
USE_GNOME+=	orbit
.endif

PLIST=	${WRKDIR}/pkg-plist
# LDAP is only used by mail and news so disable both together
.if defined(WITHOUT_MAILNEWS)
CONFIGURE_ARGS+=	--disable-ldap --disable-mailnews
.else
# mail and news desired, but not LDAP
.if defined(WITHOUT_LDAP)
CONFIGURE_ARGS+=	--disable-ldap --enable-mailnews
.else
CONFIGURE_ARGS+=	--enable-ldap --enable-mailnews
.endif
.endif

.if !defined(WITHOUT_CHATZILLA)
CONFIGURE_ARGS+=	--enable-extensions=default,irc,xmlterm
.else
CONFIGURE_ARGS+=	--enable-extensions=default,xmlterm
.endif
CONFIGURE_ENV=	MOZ_INTERNAL_LIBART_LGPL=1

.if defined(WITH_JAVASCRIPT_DEBUGGER)
CONFIGURE_ARGS+=	--enable-jsd \
			--enable-dtd-debug
.endif

.if defined(WITH_CALENDAR)
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--enable-calendar
.endif

.if defined(WITHOUT_COMPOSER)
CONFIGURE_ARGS+=	--disable-composer
.endif

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk2
PKGCONFIG_FILES=	mozilla-gtkmozembed.pc mozilla-js.pc mozilla-xpcom.pc \
			mozilla-nspr.pc mozilla-nss.pc
.else
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk
.endif

.if !defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--enable-xft
.endif

.include <bsd.port.pre.mk>

MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin \
		MOZ_INTERNAL_LIBART_LGPL=1
ALL_TARGET=	default

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-reorder
.endif

.if ${ARCH} == "alpha"
BROKEN=	"core dumps on alpha during post-build"
.endif

.if exists(${LOCALBASE}/include/freetype/freetype.h)
BROKEN="You must upgrade your freetype port to 1.3.1_2 or higher before installing Mozilla.  If you have 1.3.1_2 installed, please remove ${LOCALBASE}/include/freetype, then build Mozilla"
.endif

pre-everything::
.if defined(WITH_CALENDAR)
	@${ECHO_MSG} "Calendar is still beta software."
	@${ECHO_MSG} "Use at your own risk."
	@${ECHO_MSG} "http://mozilla.org/projects/calendar/"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
.if !defined(WITHOUT_XFT)
	@${REINPLACE_CMD} -e 's|X11/Xft/Xft\.h|X11/Xft/Xft2.h|g' \
		${WRKSRC}/gfx/src/gtk/nsDrawingSurfaceGTK.cpp \
		${WRKSRC}/gfx/src/gtk/nsFontMetricsXft.h \
		${WRKSRC}/gfx/src/gtk/nsDeviceContextGTK.cpp
.endif
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		-e 's|%%HEADERS_SUFX%%|-devel|g' \
			${WRKSRC}/config/autoconf.mk.in

post-build:
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%MOZILLA%%|${MOZILLA}|g" \
		${FILESDIR}/mozilla.sh >${WRKSRC}/${MOZILLA}
	(cd ${WRKSRC}/dist/bin; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	  ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome; \
	  ${TOUCH} ./chrome/user-skins.rdf ./chrome/user-locales.rdf)
	${FIND} ${WRKSRC}/dist/bin -type d | /usr/bin/sort -r | \
		${XARGS} ${RMDIR} 2> /dev/null || ${TRUE}

pre-install:
	${RM} -f ${PLIST}
	${TOUCH} -f ${PLIST}
	if [ ! -x ${PREFIX}/bin/mozilla -a ! -L ${PREFIX}/bin/mozilla ]; then \
	    ${ECHO_CMD} bin/mozilla >> ${PLIST} ; \
	fi
	${ECHO_CMD} bin/${MOZILLA} >> ${PLIST}
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
	    ${ECHO_CMD} lib/browser_plugins/libjavaplugin_oji.so >> ${PLIST} ; \
	fi
	cd ${WRKSRC}/dist/bin && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/${MOZILLA}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm lib/${MOZILLA}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${MOZILLA} >> ${PLIST}
.if defined(WITH_GTK2)
	for pcfile in ${PKGCONFIG_FILES}; do \
	    	${ECHO_CMD} libdata/pkgconfig/$$pcfile >> ${PLIST} ; \
	done
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/${MOZILLA}
	${CHMOD} 755 ${PREFIX}/lib/${MOZILLA}
	cd ${WRKSRC}/dist/bin && ${FIND} . | \
		cpio -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${MOZILLA}
	${INSTALL_SCRIPT} ${WRKSRC}/${MOZILLA} ${PREFIX}/bin
	if [ ! -x ${PREFIX}/bin/mozilla -a ! -L ${PREFIX}/bin/mozilla ]; then \
	    ${LN} -sf ${PREFIX}/bin/${MOZILLA} ${PREFIX}/bin/mozilla ; \
	fi
	if [ ! -d ${PREFIX}/lib/browser_plugins ]; then \
	    ${MKDIR} ${PREFIX}/lib/browser_plugins ; \
	fi
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
	    ${LN} -sf ${LOCALBASE}/jdk1.3.1/jre/plugin/i386/ns600/libjavaplugin_oji.so \
	    	${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ; \
	fi
.if defined(WITH_GTK2)
	for pcfile in ${PKGCONFIG_FILES}; do \
	    	${INSTALL_DATA} ${WRKSRC}/build/unix/$$pcfile \
			${PREFIX}/libdata/pkgconfig ; \
	done
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
