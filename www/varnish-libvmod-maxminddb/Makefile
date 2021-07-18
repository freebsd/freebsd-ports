PORTNAME=	libvmod-maxminddb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	allanjude@FreeBSD.org
COMMENT=	Varnish Module (vmod) for accessing maxminddb geoip data

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		autoreconf compiler:c11 gmake libtool pkgconfig \
		python:3.7+,build varnish:6
USE_GITHUB=	yes
GH_ACCOUNT=	scaleengine
GH_PROJECT=	libvmod_maxminddb
USE_LDCONFIG=	${PREFIX}/lib/varnach/vmods

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
