# New ports collection makefile for:	py-excelerator
# Date created:		13 May 2005
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	excelerator
PORTVERSION=	0.6.4.1
CATEGORIES=	textproc python
MASTER_SITES=	SF/py${PORTNAME}/pyExcelerator/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyexcelerator-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python library for generating Excel 97/2000/XP/2003 files

USE_ZIP=	yes
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyExcelerator

DOCSDIR=	${PREFIX}/share/doc/py-excelerator
EXAMPLESDIR=	${PREFIX}/share/examples/py-excelerator

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.bmp ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
