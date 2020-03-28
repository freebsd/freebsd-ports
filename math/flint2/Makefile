# $FreeBSD$

PORTNAME=	flint2
DISTVERSION=	g20190210
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	a143883797f27f853332adbee09b76f48b5fbfaf.patch:-p1 \
		1266c04004a846221491cb005fc8ba45cd3c75f4.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast library for number theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		compiler:c++11-lang gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	wbhart
GH_TAGNAME=	2baa9bc
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NTL
OPTIONS_DEFAULT=NTL

NTL_DESC=		Victor Shoup's Number Theory Library (used by SageMath)
NTL_LIB_DEPENDS=	libntl.so:math/ntl
NTL_CONFIGURE_WITH=	ntl

TEST_TARGET=	check

.include <bsd.port.mk>
