PORTNAME=	libomemo-c
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Implementation of the ratcheting forward secrecy protocol

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dino
MESON_ARGS=	-Dtests=false

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

.include <bsd.port.mk>
