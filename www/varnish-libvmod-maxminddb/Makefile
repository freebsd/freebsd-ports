PORTNAME=	libvmod-maxminddb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	allanjude@FreeBSD.org
COMMENT=	Varnish Module (vmod) for accessing maxminddb geoip data
WWW=		https://github.com/simonvik/libvmod_maxminddb

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		rst2man:textproc/py-docutils@${PY_FLAVOR}
LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		autoreconf compiler:c11 gmake libtool pkgconfig \
		python:build varnish:7
USE_GITHUB=	yes
GH_ACCOUNT=	scaleengine
GH_PROJECT=	libvmod_maxminddb
USE_LDCONFIG=	${PREFIX}/lib/varnach/vmods

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
