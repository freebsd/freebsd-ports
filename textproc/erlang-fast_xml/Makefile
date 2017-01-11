# $FreeBSD$

PORTNAME=	fast_xml
PORTVERSION=	1.1.19
CATEGORIES=	textproc
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang XML parsing and manipulation library

LICENSE=	APACHE20

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	processone

ERL_BUILD_DEPS=	textproc/erlang-p1_utils
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -l expat

pre-install:
	${STRIP_CMD} ${WRKSRC}/priv/lib/*.so

.include <bsd.port.mk>
