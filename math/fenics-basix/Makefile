PORTNAME=	fenics-basix
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FEniCS finite element basis evaluation library
WWW=		https://github.com/FEniCS/basix

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	xtensor>0:math/xtensor \
		xtl-quant-stack>0:devel/xtl-quant-stack
LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	FEniCS
GH_PROJECT=	basix

WRKSRC_SUBDIR=	cpp

.include <bsd.port.mk>
