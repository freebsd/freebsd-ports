# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME?=	mozilla
PORTVERSION=	1.7.b
PORTREVISION?=	1
PORTEPOCH?=	2
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	mozilla/releases/${PORTNAME}${PORTVERSION:S/.b/b/}/src \
			marcus/:local
DISTFILES=	${PORTNAME}-source-${PORTVERSION:S/.b/b/}-source${EXTRACT_SUFX} \
		 libart_lgpl-moz-2.3.10${EXTRACT_SUFX}:local

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

MOZILLA?=	mozilla-devel
MOZ_SUFX=	-devel

.if defined(WITH_GTK1)
PKGNAMESUFFIX=	-gtk
USE_GNOME=	gtk12 orbit
.else
USE_GNOME=	gtk20 libidl
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
USE_ICONV=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=					\
		--disable-auto-deps		\
		--enable-chrome-format=jar	\
		--disable-cpp-exceptions	\
		--disable-cpp-rtti		\
		--enable-crypto			\
		--disable-debug			\
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
		--enable-svg-renderer-libart	\
		--disable-tests			\
		--disable-xterm-updates		\
		--enable-xinerama		\
		--with-system-zlib		\
		--with-system-jpeg=${LOCALBASE}	\
		--with-system-mng=${LOCALBASE}	\
		--with-system-png=${LOCALBASE}	\
		--with-gssapi=/usr		\
		--with-pthreads

PLIST=		${WRKDIR}/pkg-plist
MOZ_EXTENSIONS=	default
CONFIGURE_ENV=	MOZ_INTERNAL_LIBART_LGPL=1 \
		LOCALBASE=${LOCALBASE}

.if defined(WITH_GTK1)
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk
.else
CONFIGURE_ARGS+=	--enable-default-toolkit=gtk2
.endif

ESD_LIB=	libesd.so.2
FREETYPE_LIB=	libfreetype.so.9
PKGCONFIG_FILES=mozilla-gtkmozembed mozilla-js mozilla-xpcom \
		mozilla-nspr mozilla-nss mozilla-plugin

# JPI stuff.  List paths to Java Plug-ins here in the order to try.
JPI_LIST?=\
	${LOCALBASE}/jdk1.4.2/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.4.1/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/diablo-jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so

OPTIONS=XFT "Enable Xft font anti-aliasing" on \
	CALENDAR "Enable the Calendar module" off \
	MAILNEWS "Enable Mail and News modules" on \
	COMPOSER "Enable the HTML Composer module" on \
	LDAP "Enable LDAP support for Mailnews" on \
	CHATZILLA "Enable the Chatzilla IRC module" on \
	XMLTERM "Enable the XMLTerm module" on \
	JAVASCRIPT_DEBUGGER "Enable the DTD and JavaScript debuggers" off \
	OPTIMIZED_CFLAGS "Enable -O2 optimizations" off \
	SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=	 	"Coredump during build on amd64"
.endif

.if ${ARCH} == "ia64"
BROKEN=		"Does not compile on ia64"
.endif

.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=--enable-xft
.if exists(${X11BASE}/lib/X11/fonts/mozilla/fonts.dir)
BROKEN=		Mozilla${MOZ_SUFX} and Xft2 render the mozilla-fonts \
		illegibly. Please remove the mozilla-fonts package.
.endif
.else
CONFIGURE_ARGS+=--disable-xft
.endif

.if defined(WITH_CALENDAR) && (defined(WITHOUT_MAILNEWS) || \
	defined(WITHOUT_COMPOSER))
BROKEN=	"Calendar requires Composer and Mailnews support."
.endif

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
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif
.if !defined(WITHOUT_XMLTERM)
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},xmlterm
.endif
CONFIGURE_ARGS+=	--enable-extensions=${MOZ_EXTENSIONS}

.if defined(WITH_JAVASCRIPT_DEBUGGER)
CONFIGURE_ARGS+=	--enable-jsd \
			--enable-dtd-debug
.else
CONFIGURE_ARGS+=	--disable-jsd \
			--disable-dtd-debug
.endif

.if defined(WITH_CALENDAR)
CONFIGURE_ARGS+=	--enable-calendar
.endif

.if defined(WITHOUT_COMPOSER)
CONFIGURE_ARGS+=	--disable-composer
.endif

MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin \
		MOZ_INTERNAL_LIBART_LGPL=1
ALL_TARGET=	default

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-reorder
.endif

.if ${OSVERSION} < 500035
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-nsSVGLibartGlyphMetricsFT.cpp
.endif

.if defined(WITH_SMB)
USE_GNOME+=	gnomevfs2
.else
CONFIGURE_ARGS+=--disable-gnomevfs
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
.if defined(WITH_CALENDAR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Calendar is still beta software."
	@${ECHO_MSG} "Use at your own risk."
	@${ECHO_MSG} "http://mozilla.org/projects/calendar/"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		-e 's|%%HEADERS_SUFX%%|${MOZ_SUFX}|g' \
			${WRKSRC}/config/autoconf.mk.in
	@${FIND} ${WRKSRC}/other-licenses/libical -name "*.c" | ${XARGS} \
		${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/nsprpub/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/nsprpub/configure \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${REINPLACE_CMD} -e 's|libesd\.so\.0|${ESD_LIB}|g' \
		${WRKSRC}/widget/src/gtk2/nsSound.cpp
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/modules/libpref/src/init/all.js \
		${WRKSRC}/calendar/sunbird/app/profile/all.js
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp
	@${REINPLACE_CMD} -e 's|libfreetype.so.6|${FREETYPE_LIB}|g' \
		${WRKSRC}/modules/libpref/src/init/all.js
	@for pcfile in ${PKGCONFIG_FILES}; do \
		${REINPLACE_CMD} -e 's|mozilla-xpcom|mozilla-xpcom${MOZ_SUFX}${PKGNAMESUFFIX}|g ; \
			s|mozilla-nspr|mozilla-nspr${MOZ_SUFX}${PKGNAMESUFFIX}|g' \
			${WRKSRC}/build/unix/$${pcfile}.pc.in; \
	done

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^bind[0-9]*-base-[0-9]'`" ]; then \
		${ECHO_CMD} "${PKGNAME}: bind installed with PORT_REPLACES_BASE_BIND causes build problems."; \
		${FALSE}; \
	fi

post-build:
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%MOZILLA%%|${MOZILLA}|g" \
		${FILESDIR}/mozilla.sh >${WRKSRC}/${MOZILLA}
	(cd ${WRKSRC}/dist/bin; \
		${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
		${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome; \
		${TOUCH} ./chrome/user-skins.rdf ./chrome/user-locales.rdf)
	${FIND} ${WRKSRC}/dist/bin -type d | ${SORT} -r | \
		${XARGS} ${RMDIR} 2> /dev/null || ${TRUE}

pre-install:
	${RM} -f ${PLIST}
	${TOUCH} -f ${PLIST}
	if [ ! -x ${PREFIX}/bin/mozilla -a ! -L ${PREFIX}/bin/mozilla ]; then \
		${ECHO_CMD} bin/mozilla >> ${PLIST} ; \
	fi
	${ECHO_CMD} bin/${MOZILLA} >> ${PLIST}
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
		${SED} -e 's:^:include/${MOZILLA}/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm include/${MOZILLA}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${MOZILLA} >> ${PLIST}

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
	-${RM} -fr ${PREFIX}/include/${MOZILLA}
	${MKDIR} ${PREFIX}/include/${MOZILLA}
	${CHMOD} 755 ${PREFIX}/include/${MOZILLA}
	cd ${WRKSRC}/dist/include && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${MOZILLA}

post-install:
	@${CHMOD} -R u-w ${PREFIX}/lib/${MOZILLA}/components
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
