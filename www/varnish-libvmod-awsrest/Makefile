# $FreeBSD$

PORTNAME=	libvmod-awsrest
DISTVERSIONPREFIX=	v
DISTVERSION=	62.10
#DISTVERSIONSUFFIX=	-varnish40
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Varnish Module (vmod) for generating headers for AWS REST API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libmhash.so:security/mhash

USES=		autoreconf gmake libtool pkgconfig python:2.7,build varnish
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	xcir

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
