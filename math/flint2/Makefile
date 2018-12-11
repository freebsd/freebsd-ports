# $FreeBSD$

PORTNAME=	flint2
DISTVERSION=	g20180323
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	95c58b723a9463c27d35e182dfcba6d347eca624.patch:-p1 # cmake fixes: https://github.com/wbhart/flint2/pull/459

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast library for number theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: invokes x86 assembler
BROKEN_armv6=		fails to compile: invokes x86 assembler
BROKEN_armv7=		fails to compile: invokes x86 assembler
BROKEN_mips=		fails to compile: invokes x86 assembler
BROKEN_mips64=		fails to compile: invokes x86 assembler

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake:outsource
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	wbhart
GH_TAGNAME=	83008bd
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
