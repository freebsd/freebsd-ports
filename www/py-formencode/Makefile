# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	formencode
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FormEncode-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	HTML form validation, generation, and conversion package

LICENSE=	PSFL

OPTIONS_DEFINE=	DOCS

USES=		gettext:run python:2 zip
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
