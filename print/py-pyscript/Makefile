# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	pyscript
PORTVERSION=	0.6.1
PORTREVISION=	5
CATEGORIES=	print graphics python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python module for producing high quality PostScript graphics

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TEX=	latex dvipsk

DATADIR=	${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

PYSCRIPT_EXAMPLES=	doc/examples/*.py
PYSCRIPT_MANUAL=	doc/manual/pyscript.pdf

.if defined(WITHOUT_EXAMPLES)
PLIST_SUB=	PORTEXAMPLES="@comment "
.else
PLIST_SUB=	PORTEXAMPLES=""
.endif

NO_STAGE=	yes
post-install:

.if !defined(WITHOUT_EXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PYSCRIPT_EXAMPLES} ${EXAMPLESDIR}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PYSCRIPT_MANUAL} ${DOCSDIR}
.endif

.include <bsd.port.mk>
