# Created by: Iblis Lin <iblis@hs.ntnu.edu.tw>
# $FreeBSD$

PORTNAME=	openlibm
PORTVERSION=	0.5.2
DISTVERSIONPREFIX=	v
CATEGORIES=	math
MASTER_SITES=	GH

MAINTAINER=	iblis@hs.ntnu.edu.tw
COMMENT=	High quality system independent, portable, open source libm

LICENSE=	MIT ISCL BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	JuliaLang
GH_PROJECT=	openlibm

USES=	gmake
USE_LDCONFIG=	yes

BROKEN_aarch64=		does not compile: the clang compiler does not support -march=aarch64
BROKEN_powerpc64=	does not build: gmake: clang: Command not found

.include <bsd.port.pre.mk>

MAKE_ENV+=	prefix=${PREFIX}

TEST_TARGET=	check

.include <bsd.port.post.mk>
