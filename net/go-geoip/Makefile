# $FreeBSD$

PORTNAME=	geoip
PORTVERSION=	0.0.0.20131016
CATEGORIES=	net
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	go-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Go library to wrap the libgeoip C library

LICENSE=	MIT

LIB_DEPENDS=	libGeoIP.so:net/GeoIP

DEPRECATED=     Uses legacy GeoIP 1 format which no longer works; switch to GeoIP 2 where possible
EXPIRATION_DATE=2019-02-15

USES=		compiler go
USE_GITHUB=	yes
GH_ACCOUNT=	abh
GH_TAGNAME=	da13074

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${CC} == cc
CC=	clang
.endif

.include <bsd.port.post.mk>
