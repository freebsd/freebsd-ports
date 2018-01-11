# $FreeBSD$

PORTNAME=	libu2f-host
PORTVERSION=	1.1.4
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	2
CATEGORIES=	security devel

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Yubico Universal 2nd Factor (U2F) Host C Library

LICENSE=	LGPL21+ GPLv3+
LICENSE_COMB=	multi

BUILD_DEPENDS=	gengetopt:devel/gengetopt \
		help2man:misc/help2man
LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libjson-c.so:devel/json-c
RUN_DEPENDS=	${LOCALBASE}/etc/devd/u2f.conf:security/u2f-devd

USES=	autoreconf pkgconfig gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Yubico

CONFIGURE_ARGS=	--disable-gtk-doc
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
