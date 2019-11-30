# $FreeBSD$

PORTNAME=	tvm
DISTVERSION=	0.6.0.rc0
PORTREVISION=	1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep learning compiler stack for cpu, gpu and specialized accelerators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dmlc-core>0:devel/dmlc-core \
		rang>0:devel/rang

USES=		cmake compiler:c++11-lang localbase
USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	incubator-tvm
GH_TUPLE=	dmlc:dlpack:0acb731:dlpack/3rdparty/dlpack \
		dmlc:dmlc-core:808f485:dmlc_core/3rdparty/dmlc-core
USE_LDCONFIG=	yes

LDFLAGS+=	/usr/lib/libexecinfo.so

.include <bsd.port.mk>
