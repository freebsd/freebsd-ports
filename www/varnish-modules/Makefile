# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	varnish-modules
DISTVERSIONPREFIX=	varnish-modules-
DISTVERSION=	0.9.1
CATEGORIES=	www

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Collection of Varnish Cache modules by Varnish Software

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	varnish4>=4.1.0:www/varnish4 \
		rst2man:textproc/py-docutils

USES=		autoreconf:build gmake libtool pkgconfig python:2,build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	varnish

MAKE_JOBS_UNSAFE=	yes

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
