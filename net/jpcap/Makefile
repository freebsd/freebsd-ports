# New ports collection makefile for:   jpcap
# Date created:                10 February 2010
# Whom:                        bms
#
# $FreeBSD$
#

PORTNAME=	jpcap
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	net devel java
MASTER_SITES=	http://netresearch.ics.uci.edu/kfujii/jpcap/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JNI wrapper around libpcap

LIB_DEPENDS=	pcap.1:${PORTSDIR}/net/libpcap

USE_GMAKE=	yes
USE_JAVA=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES+=	pkg-message #pkg-install
SUB_LIST+=	JAVAJARDIR="${JAVAJARDIR}"

MAKE_ENV=	JAVA_HOME="${JAVA_HOME}" JAVA="${JAVA}" JAVAC="${JAVAC}" \
		JAVAH="${JAVAH}" JAR_="${JAR}"

PLIST_FILES=	%%JAVAJARDIR%%/jpcap.jar lib/libjpcap.so

# Build JNI .so only; install pre-compiled jar.
BUILD_WRKSRC=	${WRKSRC}/src/c
ALL_TARGET=	# empty

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} =="ia64" || ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic
.endif
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ARGS+=	CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		PLATFORM="FreeBSD"

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/c/libjpcap.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/jpcap.jar ${JAVAJARDIR}

# TODO: Install docs.

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
