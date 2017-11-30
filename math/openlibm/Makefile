# Created by: Iblis Lin <iblis@hs.ntnu.edu.tw>
# $FreeBSD$

PORTNAME=	openlibm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
CATEGORIES=	math
MASTER_SITES=	GH

MAINTAINER=	iblis@hs.ntnu.edu.tw
COMMENT=	High quality system independent, portable, open source libm

LICENSE=	MIT ISCL BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_aarch64=		fails to compile: the clang compiler does not support -march=aarch64
BROKEN_armv6=		fails to compile: a parameter list without types is only allowed in a function definition
BROKEN_armv7=		fails to compile: a parameter list without types is only allowed in a function definition
BROKEN_mips=		fails to compile: No rule to make target mips/Make.files
BROKEN_mips64=		fails to compile: No rule to make target mips64/Make.files
BROKEN_powerpc64=	fails to build: gmake: clang: Command not found

USES=	gmake
USE_GITHUB=	yes
GH_ACCOUNT=	JuliaLang
GH_PROJECT=	openlibm

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

MAKE_ENV+=	prefix=${PREFIX}

TEST_TARGET=	check

.include <bsd.port.post.mk>
