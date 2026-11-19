PORTNAME=	jcef
DISTVERSION=	152.0.7977.83	# To be supported by math/scilab !!!
CATEGORIES=	www java

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java Chromium Embedded Framework
WWW=		https://github.com/chromiumembedded/java-cef

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash	\
		rsync:net/rsync
LIB_DEPENDS+=	libcef.so:www/cef	\
		libgluegen2_rt.so:graphics/jogamp-jogl
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:insource java llvm:build localbase:ldflags python shebangfix xorg
SHEBANG_GLOB=	*.sh
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	chromiumembedded
GH_PROJECT=	java-cef
GH_TAGNAME=	15a0250	# Must correspond exactly to the port www/cef!

CMAKE_OFF=	USE_SANDBOX
CMAKE_ARGS=	-DJAVA_HOME:PATH=${JAVA_HOME}	\
		-DCEF_ROOT:PATH=${LOCALBASE}/lib/cef	\
		-DCMAKE_MODULE_PATH:PATH=${LOCALBASE}/lib/cef/cmake
CONFIGURE_WRKSRC=	${WRKSRC}/jcef_build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}

MAKE_ENV=	CLASSPATH="${JAVAJARDIR}/jogl2.jar:${JAVAJARDIR}/gluegen2.jar"
INSTALL_TARGET=

BINARY_ALIAS=	jar=${JAR}	\
		javac=${JAVAC}	\
		clang-format=${LOCALBASE}/llvm${LLVM_VERSION}/bin/clang-format

SUB_FILES=	pkg-message run.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME}	\
		JAVA=${JAVA}

CI_NBR=		${PORTVERSION:R:E}

JCEF_DIST=	${WRKSRC}/binary_distrib/${OPSYS:tl}/bin
LIBS_CEF=	icudtl.dat libcef.so libEGL.so libGLESv2.so	\
		libvk_swiftshader.so libvulkan.so v8_context_snapshot.bin	\
		vk_swiftshader_icd.json chrome_100_percent.pak	\
		chrome_200_percent.pak resources.pak

OPTIONS_DEFINE=	DOCS

post-patch:
	${CP} -Rp ${WRKSRC}/tools/distrib/linux64	\
		${WRKSRC}/tools/distrib/${OPSYS:tl}

pre-configure:
.for ps in make_readme.py make_version_header.py
	${REINPLACE_CMD} -e 's|%%CI_NBR%%|${CI_NBR}|'		\
			-e 's|%%CI_HASH%%|${GH_TAGNAME}|'	\
		${WRKSRC}/tools/${ps}
.endfor
	${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|'	\
		${WRKSRC}/tools/make_distrib.sh
	${REINPLACE_CMD} -e '/gluegen-rt/d;/jogl-all/d;/natives_blob/d'	\
		${WRKSRC}/tools/distrib/${OPSYS:tl}/README.redistrib.txt
	${INSTALL_SCRIPT} ${WRKDIR}/run.sh ${WRKSRC}/tools/distrib/${OPSYS:tl}/

pre-build:
	(cd ${WRKSRC} &&	\
		${MAKE_ENV} ./tools/compile.sh ${OPSYS:tl})

do-install:
	(cd ${WRKSRC} &&	\
		${MAKE_ENV} ./tools/make_distrib.sh ${OPSYS:tl})
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/jcef ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_LIB} ${JCEF_DIST}/lib/${OPSYS:tl}/libjcef.so	\
		${STAGEDIR}${PREFIX}/lib/jcef
	${INSTALL_PROGRAM} ${JCEF_DIST}/lib/${OPSYS:tl}/jcef_helper	\
		${STAGEDIR}${PREFIX}/lib/jcef
	${INSTALL_DATA} ${JCEF_DIST}/jcef.jar ${STAGEDIR}${JAVAJARDIR}
	# Hoping that CMAKE_BUILD_TYPE was the same for www/cef
	(cd ${STAGEDIR}${PREFIX}/lib/jcef &&	\
		${LN} -sf ${LOCALBASE}/lib/cef/${CMAKE_BUILD_TYPE}/locales)
.for l in ${LIBS_CEF}
	(cd ${STAGEDIR}${PREFIX}/lib/jcef &&	\
		${LN} -sf ${LOCALBASE}/lib/cef/${CMAKE_BUILD_TYPE}/${l})
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${JCEF_DIST}/jcef-tests.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/binary_distrib/${OPSYS:tl}/run.sh	\
		${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/binary_distrib/${OPSYS:tl}/bin &&	\
		${COPYTREE_SHARE} tests ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/binary_distrib/${OPSYS:tl}/README.txt	\
		${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/binary_distrib/${OPSYS:tl}/docs &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install:
	${MKDIR} ${STAGEDIR}${JAVA_HOME}/bin
.for f in Resources/icudtl.dat Release/v8_context_snapshot.bin
	(cd ${STAGEDIR}${JAVA_HOME}/bin &&	\
		${LN} -sf ${LOCALBASE}/lib/cef/${f})
.endfor
	@${ECHO_CMD} "Remark: javadoc produces errors, but it generates the docs despite these"
	@${ECHO_CMD} "errors. See commit 4a26a1941fbfa47e268e59cfc7e8300adde160c4."

.include <bsd.port.mk>
