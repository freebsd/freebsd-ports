# Created by: Junji NAKANISHI <jun-g@daemonfreaks.com>
# $FreeBSD$

PORTNAME=	hyperestraier
PORTVERSION=	0.10.10
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-python
EXTRACT_SUFX=	.tgz

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Pure Python HyperEstraier library

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		python:2.7
USE_PYTHON=	distutils

PORTEXAMPLES=	example.py asyn_example.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}${PKGNAMESUFFIX}
OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.py ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/asyn_example.py ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
