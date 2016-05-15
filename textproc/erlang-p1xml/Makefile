# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	p1xml
PORTVERSION=	1.1.2
CATEGORIES=	textproc
PKGNAMEPREFIX=	erlang-

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Fast Expat based Erlang XML parsing library

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	processone
GH_PROJECT=	xml
GH_TAGNAME=	7ff90b7

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -l expat

post-patch:
	@${REINPLACE_CMD} -e 's|{"CFLAGS", ".*"|{"CFLAGS", "${CFLAGS}"|' \
	      -e 's|{"LDFLAGS", ".*"|{"LDFLAGS", "${LDFLAGS}"|' ${WRKSRC}/rebar.config.script.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv/lib/*.so

.include <bsd.port.mk>
