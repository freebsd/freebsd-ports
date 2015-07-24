# Created by: Victor Yagofarov <xnasx@yandex.ru>
# $FreeBSD$

PORTNAME=	librdkafka
PORTVERSION=	0.8.6
CATEGORIES=	net
DISTNAME=	${GH_ACCOUNT}-${PORTNAME}-${PORTVERSION}-${GH_TAGNAME}

MAINTAINER=	xnasx@yandex.ru
COMMENT=	Apache Kafka C/C++ library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	edenhill
GH_TAGNAME=	e3d984849a

USE_LDCONFIG=	yes

USES=	gmake perl5
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/rdkafka.pc  ${STAGEDIR}${PREFIX}/libdata/pkgconfig/librdkafka.pc

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librdkafka.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librdkafka++.so.1

.include <bsd.port.mk>
