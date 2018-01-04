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

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

PYSCRIPT_MANUAL=doc/manual/pyscript.pdf

USES=		python:2.7
USE_PYTHON=	distutils
USE_TEX=	latex dvipsk

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/doc/examples; \
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name Makefile")
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PYSCRIPT_MANUAL}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
