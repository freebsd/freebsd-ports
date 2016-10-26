# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	varnish-modules
DISTVERSIONPREFIX=	varnish-modules-
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Collection of Varnish Cache modules by Varnish Software

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils

USES=		autoreconf:build gmake libtool pkgconfig python:2,build varnish
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	varnish

MAKE_JOBS_UNSAFE=	yes

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
