# $FreeBSD$

PORTNAME=	comeonin
PORTVERSION=	2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Password hashing library for Elixir

LICENSE=	BSD3CLAUSE BSD4CLAUSE
LICENSE_COMB=	multi

USES=		elixir gmake
USE_GITHUB=	yes
GH_ACCOUNT=	elixircnx

MIX_BUILD_DEPS=	security/elixir-comeonin_i18n
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

post-build:
	${STRIP_CMD} ${WRKSRC}/priv/bcrypt_nif.so

.include <bsd.port.mk>
