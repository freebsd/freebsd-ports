# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.38
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Utilities for running CloudABI programs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	CloudABI has not yet been ported to other architectures

BUILD_DEPENDS=	${LOCALBASE}/include/cloudabi_types.h:devel/cloudabi \
		${LOCALBASE}/include/flower/protocol/switchboard.ad.h:net/flower \
		${LOCALBASE}/include/yaml2argdata/yaml_builder.h:devel/yaml2argdata
LIB_DEPENDS=	libargdata.so:devel/argdata \
		libarpc.so:devel/arpc \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake localbase:ldflags pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	NuxiNL

.include <bsd.port.mk>
