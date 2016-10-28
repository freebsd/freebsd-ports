# $FreeBSD$

PORTNAME=	libvmod-awsrest
DISTVERSIONPREFIX=${PORTNAME}-
DISTVERSION=	0.4
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Varnish Module (vmod) for generating headers for AWS REST API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libmhash.so:security/mhash

USES=		autoreconf gmake libtool pkgconfig python:2,build varnish
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	xcir
GH_TAGNAME=	v${DISTVERSION}-varnish40

.include <bsd.port.mk>
