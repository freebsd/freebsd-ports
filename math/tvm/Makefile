# $FreeBSD$

PORTNAME=	tvm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4-1440
DISTVERSIONSUFFIX=	-g347e3d9d
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep learning compiler stack for cpu, gpu and specialized accelerators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dmlc-core>0:devel/dmlc-core \
		rang>0:devel/rang

USES=		cmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_TUPLE=	dmlc:dlpack:0acb731:dlpack/3rdparty/dlpack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
