# $FreeBSD$

PORTNAME=	tvm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.20191028
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
GH_TAGNAME=	e889928
GH_TUPLE=	dmlc:dlpack:0acb731:dlpack/3rdparty/dlpack \
		dmlc:dmlc-core:808f485:dmlc_core/3rdparty/dmlc-core
USE_LDCONFIG=	yes

PORTSCOUT=	skipv:0.5 # https://github.com/dmlc/tvm/issues/3848

.include <bsd.port.mk>
