# Created by: Dryice Liu	<dryice@dryice.name>
# $FreeBSD$

PORTNAME=	Paste
PORTVERSION=	1.7.5.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tools for using a Web Server Gateway Interface stack

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes
NO_STAGE=	yes

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/_build && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
