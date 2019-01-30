# $FreeBSD$

PORTNAME=	mod_maxminddb
PORTVERSION=	1.1.0
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	MaxMind DB Apache Module

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		apache:2.4+ autoreconf gmake localbase
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	src/${PORTNAME}.c

.include <bsd.port.mk>
