# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME?=	mozilla
PORTVERSION=	1.6
PORTREVISION?=	2
PORTEPOCH?=	2
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION}/src \
		marcus/:local
DISTFILES=	${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
		libart_lgpl${EXTRACT_SUFX}:local

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2 \
		nspr4.1:${PORTSDIR}/devel/nspr

WRKSRC=		${WRKDIR}/${PORTNAME}

MOZILLA?=	mozilla

.if defined(WITH_GTK2)
PKGNAMESUFFIX=	-gtk2
USE_GNOME=	gtk20 libidl
.else
USE_GNOME=	gtk12 orbit
.endif

.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/Xft
.if exists(${X11BASE}/lib/X11/fonts/mozilla/fonts.dir)
BROKEN=		Mozilla${MOZ_SUFX} and Xft2 render the mozilla-fonts \
		illegibly. Please remove the mozilla-fonts package.
.endif
.endif

.if defined(WITH_CALENDAR) && (defined(WITHOUT_MAILNEWS) || \
	defined(WITHOUT_COMPOSER))
BROKEN=	"Calendar requires Composer and Mailnews support."
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
USE_BZIP2=	yes
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
		--disable-gtktest		\
		--disable-freetypetest		\
		--disable-installer		\
		--disable-glibtest		\
		--enable-double-buffer		\
		--enable-mathml			\
		--disable-md			\
		--disable-pedantic		\
		--disable-bidi			\
		--disable-plaintext-editor-only	\
		--enable-strip			\
		--enable-svg			\
		--disable-tests			\
		--disable-xterm-updates		\
		--enable-xinerama		\
		--with-system-zlib		\
		--with-system-jpeg=${LOCALBASE}	\
		--with-system-mng=${LOCALBASE}	\
		--with-system-png=${LOCALBASE}	\
		--with-pthreads

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
MOZ_EXTENSIONS=	default
.if !defined(WITHOUT_CHATZILLA)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif
.if !defined(WITHOUT_XMLTERM)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},xmlterm
.endif
CONFIGURE_ARGS+=	--enable-extensions=${MOZ_EXTENSIONS}
CONFIGURE_ENV=	MOZ_INTERNAL_LIBART_LGPL=1

.if defined(WITH_JAVASCRIPT_DEBUGGER)
CONFIGURE_ARGS+=	--enable-jsd \
			--enable-dtd-debug
.else
CONFIGURE_ARGS+=	--disable-jsd \
			--disable-dtd-debug
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
.else
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk
.endif

.if !defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--enable-xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

PKGCONFIG_FILES=mozilla-gtkmozembed mozilla-js mozilla-xpcom \
		mozilla-nspr mozilla-nss mozilla-plugin

# JPI stuff.  List paths to Java Plug-ins here in the order to try.
JPI_LIST=\
	${LOCALBASE}/jdk1.4.2/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.4.1/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/diablo-jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so

.include <bsd.port.pre.mk>

MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin \
		MOZ_INTERNAL_LIBART_LGPL=1
ALL_TARGET=	default

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-reorder
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=		-O2
CONFIGURE_ARGS+=	--enable-optimize=-O2
.endif

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	"core dumps on alpha during post-build"
.endif

.if exists(${LOCALBASE}/include/freetype/freetype.h)
BROKEN="You must upgrade your freetype port to 1.3.1_2 or higher before installing Mozilla.  If you have 1.3.1_2 installed, please remove ${LOCALBASE}/include/freetype, then build Mozilla"
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Mozilla has the following tunable option(s):"
	@${ECHO_MSG} "	WITHOUT_XFT=yes		Disables Xft anti-aliasing support"
	@${ECHO_MSG} "	WITH_CALENDAR=yes	Enables the Calendar module (requires Mailnews and Composer modules)"
	@${ECHO_MSG} "	WITHOUT_MAILNEWS=yes	Disables the Mail and News modules"
	@${ECHO_MSG} "	WITHOUT_COMPOSER=yes	Disables the HTML Composer module"
	@${ECHO_MSG} "	WITHOUT_LDAP=yes	Disables LDAP support within the Mailnews module"
	@${ECHO_MSG} "	WITHOUT_CHATZILLA=yes	Disable the Chatzilla IRC module"
	@${ECHO_MSG} "	WITHOUT_XMLTERM=yes	Disable the XMLTerm module"
	@${ECHO_MSG} "	WITH_JAVASCRIPT_DEBUGGER=yes		Enable the DTD and JavaScript debuggers"
	@${ECHO_MSG} "	WITH_OPTIMIZED_CFLAGS=yes	Enable -O2 optimization"
	@${ECHO_MSG} ""
.if defined(WITH_CALENDAR)
	@${ECHO_MSG} "Calendar is still beta software."
	@${ECHO_MSG} "Use at your own risk."
	@${ECHO_MSG} "http://mozilla.org/projects/calendar/"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		-e 's|%%HEADERS_SUFX%%|${MOZ_SUFX}|g' \
			${WRKSRC}/config/autoconf.mk.in
	@${FIND} ${WRKSRC}/other-licenses/libical -name "*.c" | ${XARGS} \
		${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/nsprpub/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/nsprpub/configure \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@for pcfile in ${PKGCONFIG_FILES}; do \
		${REINPLACE_CMD} -e 's|mozilla-xpcom|mozilla-xpcom${MOZ_SUFX}${PKGNAMESUFFIX}|g ; \
			s|mozilla-nspr|mozilla-nspr${MOZ_SUFX}${PKGNAMESUFFIX}|g' \
			${WRKSRC}/build/unix/$${pcfile}.pc.in; \
	done

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
	if [ "${MOZILLA}" != "mozilla" ]; then \
		${ECHO_CMD} bin/${MOZILLA} >> ${PLIST} ; \
	fi
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
				${ECHO_CMD} lib/browser_plugins/libjavaplugin_oji.so >> ${PLIST} ; \
				break; \
			fi; \
		done; \
		${ECHO_CMD} @dirrm lib/browser_plugins >> ${PLIST} ; \
	fi
	cd ${WRKSRC}/dist/bin && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/${MOZILLA}/:' >> ${PLIST} \
			&& ${FIND} -d * -type d | \
			${SED} -e 's:^:@dirrm lib/${MOZILLA}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${MOZILLA} >> ${PLIST}
	for pcfile in ${PKGCONFIG_FILES}; do \
		${ECHO_CMD} libdata/pkgconfig/$${pcfile}${MOZ_SUFX}${PKGNAMESUFFIX}.pc >> ${PLIST} ; \
	done
	cd ${WRKSRC}/dist/include && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:include/mozilla/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm include/mozilla/:' >> ${PLIST}
	${ECHO_CMD} @dirrm include/mozilla >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/${MOZILLA}
	${CHMOD} 755 ${PREFIX}/lib/${MOZILLA}
	cd ${WRKSRC}/dist/bin && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${MOZILLA}
	${INSTALL_SCRIPT} ${WRKSRC}/${MOZILLA} ${PREFIX}/bin
	if [ ! -x ${PREFIX}/bin/mozilla -a ! -L ${PREFIX}/bin/mozilla ]; then \
		${LN} -sf ${PREFIX}/bin/${MOZILLA} ${PREFIX}/bin/mozilla ; \
	fi
	if [ ! -d ${PREFIX}/lib/browser_plugins ]; then \
		${MKDIR} ${PREFIX}/lib/browser_plugins ; \
	fi
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
		${INSTALL_DATA} ${WRKSRC}/build/unix/$${pcfile}.pc \
			${PREFIX}/libdata/pkgconfig/$${pcfile}${MOZ_SUFX}${PKGNAMESUFFIX}.pc ; \
	done
	-${RM} -fr ${PREFIX}/include/mozilla
	${MKDIR} ${PREFIX}/include/mozilla
	${CHMOD} 755 ${PREFIX}/include/mozilla
	cd ${WRKSRC}/dist/include && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/mozilla

post-install:
	@${CHMOD} -R u-w ${PREFIX}/lib/${MOZILLA}/components
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
