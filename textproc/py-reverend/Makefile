# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	reverend
PORTVERSION=	0.3
CATEGORIES=	textproc mail math python
MASTER_SITES=	SF/${PORTNAME}/Reverend/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Reverend-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple Bayesian classifier written in Python

USES=		python
USE_PYTHON=	distutils autoplist
OPTIONS_DEFINE=	EXAMPLES

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
