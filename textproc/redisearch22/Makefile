PORTNAME=	redisearch22
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.10
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-text search over Redis

LICENSE=	UNKNOWN
LICENSE_NAME=	Redis Source Available License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		cmake compiler

USE_GITHUB=	yes
GH_ACCOUNT=	RediSearch
GH_PROJECT=	RediSearch

CMAKE_ARGS=	-DGIT_DESCRIBE_VERSION:STRING=${PKGVERSION} \
		-DOS=freebsd

PLIST_FILES=	lib/redisearch22.so

do-install:
	${INSTALL_LIB} ${INSTALL_WRKSRC}/redisearch.so \
		${STAGEDIR}${PREFIX}/lib/redisearch22.so

.include <bsd.port.mk>
