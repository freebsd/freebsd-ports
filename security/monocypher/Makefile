PORTNAME=	monocypher
DISTVERSION=	4.0.2
CATEGORIES=	security
MASTER_SITES=	https://monocypher.org/download/

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Compact cryptographic library in C
WWW=		https://monocypher.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.md

USE_CSTD=	c99
USE_LDCONFIG=	yes

MAKEFILE=	makefile
ALL_TARGET=	all
TEST_TARGET=	test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmonocypher.so.*

.include <bsd.port.mk>
