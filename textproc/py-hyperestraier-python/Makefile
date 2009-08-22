# New ports collection makefile for:    py-hyperestraier-python
# Date created:                         30 March 2007
# Whom:                                 Junji NAKANISHI <jun-g@daemonfreaks.com>
#
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
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PORTEXAMPLES=	example.py asyn_example.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}${PKGNAMESUFFIX}

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.py ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/asyn_example.py ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
