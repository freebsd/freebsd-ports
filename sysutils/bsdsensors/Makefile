PORTNAME=	bsdsensors
DISTVERSION=	0.1.20250325
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Tool to read sensors and control fan speed
WWW=		https://github.com/henryhu/bsdsensors

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf \
		libgflags.so:devel/gflags \
		libabsl_base.so:devel/abseil

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	henryhu

.include <bsd.port.mk>
