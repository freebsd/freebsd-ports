# Created by: Marc van Woerkom <3d@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvrml
PORTVERSION=	0.18.9
PORTREVISION=	6
CATEGORIES=	www graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VRML97 runtime and browser

BROKEN=		does not build

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone
LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig		\
		js.1:${PORTSDIR}/lang/spidermonkey17			\
		jpeg.11:${PORTSDIR}/graphics/jpeg			\
		png15:${PORTSDIR}/graphics/png				\
		curl:${PORTSDIR}/ftp/curl				\
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_GL=		yes
USES=		 pathfix pkgconfig
USE_GNOME=	libglade2 libgnomeui
USE_SDL=	sdl
USE_JAVA=	yes
USE_GCC=	yes
GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure
CONFIGURE_ARGS=	--enable-gecko-rpath \
		--disable-mozilla-plugin
CONFIGURE_ENV=	LIBS="-lm" BOOST_LIB_SUFFIX=""
CPPFLAGS+=	-I${LOCALBASE}/include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/${OPSYS:L} \
		-I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib -L${JAVA_HOME}/jre/lib/${ARCH}/client -pthread
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GECKO=	libxul

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=openvrml.so
MAKE_JOBS_UNSAFE=yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

.if ${ARCH} == "sparc64"
BROKEN=		Gets internal gcc error on ${ARCH}
.endif

LIB_DEPENDS+=	boost_regex:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS+=	boost_python:${PORTSDIR}/devel/boost-python-libs

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
		${WRKSRC}/src/Makefile.in
.if ${GECKO} != "firefox"
	${REINPLACE_CMD} -e "s|FIREFOX_JS|${GECKO:S/19//:U}_JS|g;s|firefox-js|${GECKO:S/19//}-js|"	\
		${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|firefox-plugin|${GECKO:S/19//}-plugin|g"	\
		${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|mozilla-plugin|${GECKO:S/19//}|g" \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|boost_thread-mt|boost_thread|g" \
		${WRKSRC}/configure
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
