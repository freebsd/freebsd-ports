# Ports collection makefile for:        py-networkx
# Date created:			June, 20  2008
# Whom:				dikshie
# $FreeBSD$

PORTNAME=	networkx
PORTVERSION=	0.36
CATEGORIES=	math python
MASTER_SITES=	https://networkx.lanl.gov/download/networkx/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for complex network

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%DOCSDIR%%,${DOCSDIR},' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},' ${WRKSRC}/setup.py

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
