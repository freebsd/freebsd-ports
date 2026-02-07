PORTNAME=	wifibox
PORTVERSION=	1.7.0
CATEGORIES=	net

MAINTAINER=	pali.gabor@gmail.com
COMMENT=	Embedded (virtualized) wireless router
WWW=		https://github.com/pgj/freebsd-wifibox

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	wifibox-core>0:net/wifibox-core

USES=	metaport

.include "${.CURDIR}/../wifibox-alpine/flavors.mk"

.for flavor in ${_FLAVORS}
${flavor}_RUN_DEPENDS=         wifibox-alpine-${flavor}>0:net/wifibox-alpine@${flavor}
${flavor}_PKGNAMESUFFIX=       -${flavor}
.endfor

default_RUN_DEPENDS=           wifibox-alpine>0:net/wifibox-alpine

.include <bsd.port.mk>
