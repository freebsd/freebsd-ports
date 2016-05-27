# $FreeBSD$

PORTNAME=	libvmod-maxminddb
DISTVERSION=	1.0.0
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Varnish Module (vmod) for accessing maxminddb geoip data

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	varnish4>=4.1.0:www/varnish4 \
		rst2man:textproc/py-docutils

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

RUN_DEPENDS=	varnish4>=4.1.0:www/varnish4

USES=		autoreconf gmake libtool pkgconfig python:2,build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	simonvik
GH_PROJECT=	libvmod_maxminddb
GH_TAGNAME=	4ae6a7f

.include <bsd.port.mk>
