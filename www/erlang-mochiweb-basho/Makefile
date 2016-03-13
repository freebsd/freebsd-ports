# $FreeBSD$

PORTNAME=	mochiweb
PORTVERSION=	2.9.0p2
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
GH_TAGNAME=	4d38821	# required

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
