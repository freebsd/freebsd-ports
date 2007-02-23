# ex:ts=8
# Ports collection makefile for:	py-IMDbPY
# Date created:			Jul 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	imdbpy
PORTVERSION=	2.9
CATEGORIES=	www python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IMDbPY-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Retrieve and manage the data of the IMDb movie database

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
.endif
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/bin/ ${EXAMPLESDIR}

.include <bsd.port.mk>
