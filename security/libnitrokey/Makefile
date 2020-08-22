# Created by: Thibault Payet <monwarez@mailoo.org>
# $FreeBSD$

PORTNAME=	libnitrokey
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6-RC1
CATEGORIES=	security

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Libnitrokey is a project to communicate with Nitrokey devices

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libudev.so:devel/libudev-devd

USES=		cmake compiler:c++14-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Nitrokey

USE_LDCONFIG=	yes

.include <bsd.port.mk>
