# $FreeBSD$

PORTNAME=	comeonin
PORTVERSION=	3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Password hashing library for Elixir

LICENSE=	BSD3CLAUSE BSD4CLAUSE
LICENSE_COMB=	multi

USES=		elixir gmake
USE_GITHUB=	yes
GH_ACCOUNT=	elixircnx

MIX_BUILD_DEPS=	devel/elixir-make \
		security/elixir-comeonin_i18n
MIX_RUN_DEPS:=	security/elixir-comeonin_i18n

OPTIONS_DEFINE=	DOCS

post-build:
	${STRIP_CMD} ${WRKSRC}/priv/bcrypt_nif.so

.include <bsd.port.mk>
