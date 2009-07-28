# New ports collection makefile for:	OpenVRML
# Date created:				8 Jan 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openvrml
PORTVERSION=	0.17.5
PORTREVISION=	5
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VRML97 runtime and browser

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone	\
		pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig		\
		js.1:${PORTSDIR}/lang/spidermonkey			\
		jpeg.10:${PORTSDIR}/graphics/jpeg			\
		png.5:${PORTSDIR}/graphics/png				\
		curl.5:${PORTSDIR}/ftp/curl

USE_GL=		yes
USE_GNOME=	gnomehack libglade2 libgnomeui
USE_SDL=	sdl
USE_JAVA=	yes
GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure mozilla-plugin/configure lib/gtkglext/configure
CONFIGURE_ARGS=	--enable-gecko-rpath
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/${OPSYS:L}"	\
		LDFLAGS="-L${LOCALBASE}/lib -L${JAVA_HOME}/jre/lib/${ARCH}/client ${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"	\
		LIBS="-lm"
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GECKO=	firefox seamonkey

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=openvrml.so

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

.if ${OSVERSION} < 700042
BROKEN=		Does not compile
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Gets internal gcc error on ${ARCH}
.endif

LIB_DEPENDS+=	boost_regex.4:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS+=	boost_python.4:${PORTSDIR}/devel/boost-python-libs

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: building this port eats up to 1.5 GB of RAM (32 bits) or 3 GB (64 bits)"
	@${ECHO_MSG} "of RAM; do not try to build it on a small configuration!"
	@${ECHO_MSG}

pre-configure:
	${REINPLACE_CMD} -e	\
		's|JNI_LIBS="|JNI_LIBS="-L${JAVA_HOME}/jre/lib/${ARCH}/client -Wl,-rpath,${JAVA_HOME}/jre/lib/${ARCH}/client |'	\
		${WRKSRC}/configure
	${REINPLACE_CMD} -e	\
		's|-rpath $$(libdir)|-rpath $$(libdir) -rpath ${JAVA_HOME}/jre/lib/${ARCH}/client|'	\
		${WRKSRC}/src/Makefile.in
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
	    	's|-DG[[:alpha:]]*_DISABLE_DEPRECATED||g'
.for cfg in ${LIBTOOLFILES}
	${REINPLACE_CMD} -e	\
		"/hardcode_libdir_flag_spec/s|\(=.\)\(.*\)\(\$$libdir\)|& \2${JAVA_HOME}/jre/lib/${ARCH}/client|"	\
		${WRKSRC}/${cfg}
.endfor
	${REINPLACE_CMD} -e 's|$$(libdir)/mozilla/plugins|${WEBPLUGINS_DIR}|'	\
		${WRKSRC}/mozilla-plugin/src/Makefile.in
.if ${GECKO} != "firefox"
	${REINPLACE_CMD} -e "s|FIREFOX_JS|${GECKO:U}_JS|g;s|firefox-js|${GECKO}-js|"	\
		${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|firefox-plugin|${GECKO}-plugin|g"	\
		${WRKSRC}/mozilla-plugin/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/manual/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/models/*.wrl ${EXAMPLESDIR}
.endif

regression-test:
	(cd ${BUILD_WRKSRC}/tests ;	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check-TESTS)

.include <bsd.port.post.mk>
