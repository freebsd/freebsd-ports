# $FreeBSD$

PORTNAME=	mochiweb
PORTVERSION=	2.18.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang library for building lightweight HTTP servers

LICENSE=	MIT

CONFLICTS=	mochiweb-basho-[0-9]*

USES=		cpe erlang:rebar
CPE_VENDOR=	mochiweb_project
USE_GITHUB=	yes
GH_ACCOUNT=	mochi

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
