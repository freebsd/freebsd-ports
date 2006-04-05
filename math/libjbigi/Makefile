# New ports collection makefile for:	i2p jbigi JNI
# Date created:		Fri Dec 23 12:02:32 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libjbigi
PORTVERSION=	0.6.1.13
CATEGORIES=	math java
MASTER_SITES=	http://dev.i2p.net/i2p/
DISTNAME=	i2p-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	i2p JNI to GNU MP Bignum library (libgmp)

BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.a:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VERSION=	1.4
JAVA_OS=	native

WRKSRC=		${WRKDIR}/i2p_${PORTVERSION:S/./_/g}/core/c

PLIST_FILES=	%%JAVAJARDIR%%/jbigi.jar

JBIGI_BUILD_ENV=	\
			CC="${CC}" \
			CFLAGS="${CFLAGS}" \
			LDFLAGS="${LDFLAGS} -static" \
			JAVA_HOME="${JAVA_HOME}" \
			LOCALBASE="${LOCALBASE}"
JBIGI_LIBS=	\
		libjbigi-freebsd-none.so

do-install:
	@${INSTALL_DATA} ${WRKSRC}/jbigi.jar \
		${JAVAJARDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
JBIGI_BUILD_JCPUID=	yes
JBIGI_LIBS+=	libjbigi-freebsd-x86.so
.endif

do-build:
## build JNI
.ifdef(JBIGI_BUILD_JCPUID)
# jcpuid
	cd ${BUILD_WRKSRC}/jcpuid && \
		${ENV} ${JBIGI_BUILD_ENV} \
			${SH} ./build.sh
.endif
# jbigi
	cd ${BUILD_WRKSRC}/jbigi && \
		${ENV} ${JBIGI_BUILD_ENV} \
			${SH} ./build_jbigi.sh static
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
