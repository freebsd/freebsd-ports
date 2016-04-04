# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libjbigi
PORTVERSION=	0.8.7
CATEGORIES=	math java
MASTER_SITES=	http://mirror.i2p2.de/ \
		GOOGLE_CODE
DISTNAME=	i2psource_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	i2p JNI to GNU MP Bignum library (libgmp)

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		tar:bzip2
USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VERSION=	1.6+
JAVA_OS=	native
PROJECTHOST=	i2p

WRKSRC=		${WRKDIR}/i2p-${PORTVERSION}/core/c

PLIST_FILES=	%%JAVAJARDIR%%/jbigi.jar

JBIGI_BUILD_ENV=	\
			CC="${CC}" \
			CFLAGS="${CFLAGS} -fPIC -DPIC" \
			LDFLAGS="${LDFLAGS}" \
			JAVA_HOME="${JAVA_HOME}" \
			LOCALBASE="${LOCALBASE}"
JBIGI_LIBS=	\
		libjbigi-freebsd-none.so

do-install:
	@${INSTALL_DATA} ${WRKSRC}/jbigi.jar \
		${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
JBIGI_BUILD_JCPUID=	yes
.endif

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
JBIGI_LIBS+=	libjbigi-freebsd-x86.so
.endif

do-build:
## build JNI
.ifdef(JBIGI_BUILD_JCPUID)
# jcpuid
	cd ${BUILD_WRKSRC}/jcpuid && \
		${SETENV} ${JBIGI_BUILD_ENV} \
			${SH} ./build.sh
.endif
# jbigi
	cd ${BUILD_WRKSRC}/jbigi && \
		${SETENV} ${JBIGI_BUILD_ENV} \
			${SH} ./build_jbigi.sh dynamic
## prepare jar
.ifdef(JBIGI_BUILD_JCPUID)
# jcpuid
	@${MKDIR} ${WRKSRC}/t/freenet/support/CPUInformation/
	@${CP} ${WRKSRC}/jcpuid/lib/freenet/support/CPUInformation/*jcpuid* \
		${WRKSRC}/t/freenet/support/CPUInformation/
.endif
# jbigi
	@${MKDIR} ${WRKSRC}/t/net/i2p/util
.for lib in ${JBIGI_LIBS}
	@${CP} ${WRKSRC}/jbigi/libjbigi.so \
		${WRKSRC}/t/net/i2p/util/${lib}
.endfor
	@cd ${WRKSRC}/t && ${JAR} cf ../jbigi.jar .

.include <bsd.port.post.mk>
