# Created by: anders
# $FreeBSD$

PORTNAME=	libvmod-header
DISTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Varnish Module (vmod) for manipulation of duplicated headers

LICENSE=	BSD2CLAUSE

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

BUILD_DEPENDS=	varnish4>=4.0.2:www/varnish4 \
		rst2man:textproc/py-docutils

USES=		autoreconf gmake libtool pkgconfig python:2,build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
PLIST_FILES=	man/man3/vmod_header.3.gz lib/varnish/vmods/libvmod_header.so
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	varnish
GH_TAGNAME=	e87ac92

.include <bsd.port.mk>
