# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvmod-saintmode
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Varnish Module (vmod) for detecting failing backends

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	varnish4>=4.1.0:www/varnish4 \
		rst2man:textproc/py-docutils

USES=		autoreconf gmake libtool pkgconfig python:2,build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	varnish

.include <bsd.port.mk>
