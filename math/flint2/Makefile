# $FreeBSD$

PORTNAME=	flint2
DISTVERSION=	g20190210
CATEGORIES=	math

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

USES=		cmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	wbhart
GH_TAGNAME=	2baa9bc
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
