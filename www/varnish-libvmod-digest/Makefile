# $FreeBSD$

PORTNAME=	libvmod-digest
DISTVERSION=	1.0.2-6
DISTVERSIONSUFFIX=	-g1793bea
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	allanjude@FreeBSD.org
COMMENT=	Varnish Module (vmod) for computing message digests and HMAC

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
LIB_DEPENDS=	libmhash.so:security/mhash

USES=		autoreconf gmake libtool pkgconfig python:3.7+,build varnish:6
USE_GITHUB=	yes
GH_ACCOUNT=	varnish
USE_LDCONFIG=	${PREFIX}/lib/varnach/vmods

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
