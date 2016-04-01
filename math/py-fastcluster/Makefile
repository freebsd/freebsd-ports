# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	fastcluster
PORTVERSION=	1.1.13
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Python functions for hierarchical clustering

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy

PORTDOCS=	CITATION.txt \
		INSTALL.txt \
		NEWS.txt \
		README.txt

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
