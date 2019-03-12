# $FreeBSD$

PORTNAME=	re-flex
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Regex-centric, fast and flexible scanner generator for C++

LICENSE=	BSD3CLAUSE

CONFLICTS_INSTALL=	reflex

USES=		autoreconf compiler:c++11-lib gmake

USE_GITHUB=	yes
GH_ACCOUNT=	Genivia
GH_PROJECT=	RE-flex

GNU_CONFIGURE=	yes

TEST_TARGET=	test

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/reflex
	(cd ${WRKSRC}/include/reflex && \
	 ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/include/reflex)

.include <bsd.port.mk>
