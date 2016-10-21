# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.2.14
PORTREVISION=	1
CATEGORIES=	www security
PKGNAMESUFFIX=	-suricata

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

USE_GITHUB=	yes
GH_ACCOUNT=	inliniac

USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	libhtp-[0-9]*

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
