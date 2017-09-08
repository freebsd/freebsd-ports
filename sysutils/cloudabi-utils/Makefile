# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.30
CATEGORIES=	sysutils

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Utilities for running CloudABI programs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 i386
ONLY_FOR_ARCHS_REASON=	CloudABI has not yet been ported to other architectures

BUILD_DEPENDS=	${LOCALBASE}/include/cloudabi_types.h:devel/cloudabi \
		${LOCALBASE}/include/flower/protocol/switchboard.ad.h:net/flower \
		${LOCALBASE}/include/yaml2argdata/yaml_builder.h:devel/yaml2argdata
LIB_DEPENDS=	libargdata.so:devel/argdata \
		libarpc.so:devel/arpc \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake localbase:ldflags pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	NuxiNL

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100511
IGNORE=		requires various C++17 features
.endif

.include <bsd.port.post.mk>
