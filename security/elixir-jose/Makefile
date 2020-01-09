# $FreeBSD$

PORTNAME=	jose
PORTVERSION=	1.10.1
CATEGORIES=	security
PKGNAMEPREFIX=	elixir-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	JSON Object Signing and Encryption (JOSE) for Elixir

LICENSE=	MPL20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	potatosalad
GH_PROJECT=	erlang-jose
DOCSDIR=	${PREFIX}/share/doc/elixir-${PORTNAME}
NO_ARCH=	yes

MIX_BUILD_DEPS=	security/erlang-jose
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
