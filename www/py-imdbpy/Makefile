# ex:ts=8
# Ports collection makefile for:	py-IMDbPY
# Date created:			Jul 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	imdbpy
PORTVERSION=	3.9
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/IMDbPY/${PORTVERSION} CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IMDbPY-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Retrieve and manage the data of the IMDb movie database

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	IMDbPY

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/bin/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
