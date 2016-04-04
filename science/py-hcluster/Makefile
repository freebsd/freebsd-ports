# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	hcluster
PORTVERSION=	0.2.0
PORTREVISION=	8
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hierarchical Clustering Package For Scipy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_hierarchy_wrap.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_distance_wrap.so

.include <bsd.port.mk>
