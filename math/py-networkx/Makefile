# Ports collection makefile for:        py-networkx
# Date created:			June, 20  2008
# Whom:				dikshie
# $FreeBSD$

PORTNAME=	networkx
PORTVERSION=	1.4
CATEGORIES=	math python
MASTER_SITES=	http://networkx.lanl.gov/download/networkx/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for complex network

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples \
		&& ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.txt ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
