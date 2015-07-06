# $FreeBSD$

PORTNAME=	mochiweb
PORTVERSION=	2.9.0p1
PORTREVISION=	1
CATEGORIES=	www devel
PKGNAMEPREFIX=	erlang-
PKGNAMESUFFIX=	-basho

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang library for building lightweight HTTP servers (Basho fork)

LICENSE=	MIT

CONFLICTS=	mochiweb-[0-9]*

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	basho
GH_TAGNAME=	ade2a9b	# required

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
