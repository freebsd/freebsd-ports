# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ntraceroute
PORTVERSION=	6.4.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ZI/ntraceroute
DISTNAME=	traceroute.c
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Ubiquitous network routing analysis tool

WRKSRC=		${WRKDIR}

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

PLIST_FILES=	sbin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100030
BUILD_FLAGS=	-DBYTESWAP_IP_FLAGS -DBYTESWAP_IP_LEN
.endif

do-build:
	${CC} ${BUILD_FLAGS} -o ${WRKSRC}/${PORTNAME} -lm \
	    ${WRKSRC}/${DISTFILES}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.post.mk>
