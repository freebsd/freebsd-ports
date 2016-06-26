# Created by: Victor Yagofarov <xnasx@yandex.ru>
# $FreeBSD$

PORTNAME=	librdkafka
PORTVERSION=	0.9.1
CATEGORIES=	net

MAINTAINER=	xnasx@yandex.ru
COMMENT=	Apache Kafka C/C++ library

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	edenhill

USE_LDCONFIG=	yes

USES=	gmake perl5 python
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000 && ${ARCH} == "i386"
CFLAGS+=	-march=pentium
.endif

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librdkafka.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librdkafka++.so.1

.include <bsd.port.post.mk>
