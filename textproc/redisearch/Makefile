# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redisearch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.15
CATEGORIES=	textproc

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Full-text search over Redis

LICENSE=	UNKNOWN
LICENSE_NAME=	Redis Source Available License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		cmake compiler

USE_GITHUB=	yes
GH_ACCOUNT=	RediSearch
GH_PROJECT=	RediSearch

CMAKE_ARGS=	-DGIT_DESCRIBE_VERSION:STRING=${PKGVERSION}

PLIST_FILES=	lib/redisearch.so

do-install:
	${INSTALL_LIB} ${INSTALL_WRKSRC}/redisearch.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
