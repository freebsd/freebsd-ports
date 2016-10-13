# $FreeBSD$

PORTNAME=	libvmod-digest
DISTVERSIONPREFIX=${PORTNAME}-
DISTVERSION=	1.0.1
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	allanjude@FreeBSD.org
COMMENT=	Varnish Module (vmod) for computing message digests and HMAC

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	varnish4>=4.1.0:www/varnish4 \
		rst2man:textproc/py-docutils
LIB_DEPENDS=	libmhash.so:security/mhash
RUN_DEPENDS=	varnish4>=4.1.0:www/varnish4

USES=		autoreconf gmake libtool pkgconfig python:2,build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	varnish

.include <bsd.port.mk>
