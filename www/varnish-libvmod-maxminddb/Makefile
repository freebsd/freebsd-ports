# $FreeBSD$

PORTNAME=	libvmod-maxminddb
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Varnish Module (vmod) for accessing maxminddb geoip data

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		autoreconf compiler:c11 gmake libtool pkgconfig \
		python:2.7,build varnish
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	simonvik
GH_PROJECT=	libvmod_maxminddb
GH_TAGNAME=	4ae6a7f

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
