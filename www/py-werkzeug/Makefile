# Created by: Moggie <moggie@elasticmind.net>
# $FreeBSD$

PORTNAME=	werkzeug
PORTVERSION=	0.9.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Werkzeug-${DISTVERSION}

MAINTAINER=	moggie@elasticmind.net
COMMENT=	Python utilities collection for building WSGI applications

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	EXAMPLES

USES=		python
USE_PYTHON=	distutils autoplist

EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
