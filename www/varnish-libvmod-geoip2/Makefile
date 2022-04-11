PORTNAME=	libvmod-geoip2
PORTVERSION=	20210423
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Varnish Module (vmod) to query MaxMind GeoIP2 DB files

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		autoreconf:build gmake libtool pkgconfig \
		python:3.7+,build varnish:7
USE_GITHUB=	yes
GH_ACCOUNT=	fgsch
GH_PROJECT=	libvmod-geoip2
GH_TAGNAME=	68a7f45
USE_LDCONFIG=	${PREFIX}/lib/varnish/vmods

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

pre-configure:
	(cd ${WRKSRC} && ${SH} ./autogen.sh)

.include <bsd.port.mk>
