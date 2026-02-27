PORTNAME=	USearch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.24.0
CATEGORIES=	math java

MAINTAINER=	markus.graf@markusgraf.net
COMMENT=	Search & Clustering engine library (C, C++ and Java JNI)
WWW=		https://unum.cloud/usearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	Tests crash on i386

USES=		cmake java

USE_GITHUB=	yes
GH_ACCOUNT=	unum-cloud

CMAKE_ON=	USEARCH_USE_FP16LIB    \
		USEARCH_USE_SIMSIMD    \
		USEARCH_BUILD_TEST_C   \
		USEARCH_BUILD_TEST_CPP \
		USEARCH_BUILD_LIB_C    \
		USEARCH_USE_OPENMP     \
		USEARCH_BUILD_JNI

CMAKE_OFF=      USEARCH_BUILD_BENCH_CPP

CMAKE_ARGS=	-DJAVA_INCLUDE_PATH=${JAVA_HOME}/include \
		-DJAVA_HOME=${JAVA_HOME}

JAVA_VERSION=	21

USE_LDCONFIG=	yes

GH_TUPLE=	maratyszcza:FP16:0a92994d729ff76a58f692d3028ca1b64b145d91:fp16/fp16 \
		ashvardanian:StringZilla:v3.12.6:sz/stringzilla \
		ashvardanian:SimSIMD:v6.5.13:sim/simsimd

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 # for simsimd
CXXFLAGS=	-march=x86-64
.endif

post-build:
	cd ${WRKSRC} && ${JAVAC} -classpath java -encoding UTF-8 -h java/cloud/unum/usearch -d bin java/cloud/unum/usearch/Index.java
	${MKDIR} ${WRKSRC}/bin/usearch-native
	${INSTALL_LIB} ${BUILD_WRKSRC}/libusearch_jni.so ${WRKSRC}/bin/usearch-native/
	cd ${WRKSRC} && ${JAR} cvf usearch.jar -C bin .

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/usearch
	${INSTALL_DATA} ${WRKSRC}/include/usearch/*.hpp ${STAGEDIR}${PREFIX}/include/usearch/
	${INSTALL_DATA} ${WRKSRC}/c/usearch.h ${STAGEDIR}${PREFIX}/include/usearch/
	${INSTALL_LIB} ${BUILD_WRKSRC}/libusearch_c.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${BUILD_WRKSRC}/libusearch_static_c.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/usearch.jar ${STAGEDIR}${JAVAJARDIR}/usearch-${DISTVERSION}.jar
	${RLN} usearch-${DISTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/usearch.jar

do-test:
	cd ${BUILD_WRKSRC} && ./test_c
	cd ${BUILD_WRKSRC} && ./test_cpp
	cd ${WRKSRC} && ${JAVA} -classpath bin cloud.unum.usearch.Index
	cd ${WRKSRC} && ${JAVA} -classpath usearch.jar cloud.unum.usearch.Index

.include <bsd.port.post.mk>
