PORTNAME=	qmk_hid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.12
PORTREVISION=	9
CATEGORIES=	sysutils

MAINTAINER=	dhs@frame.work
COMMENT=	Framework Computer QMK HID Utility
WWW=		https://github.com/FrameworkComputer/qmk_hid

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	FrameworkComputer

PLIST_FILES=	bin/qmk_hid

.include <bsd.port.mk>
