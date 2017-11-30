# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	qp
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/qp/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python web framework to use qpy and durus together

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}durus>=0:devel/py-durus@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qpy>=1.7:www/py-qpy@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_PYTHON=	distutils
USES=		python:2

SUB_FILES=	pkg-message

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt
PORTEXAMPLES=	*

post-build:
	@${STRIP_CMD} ${WRKSRC}/build/lib.*/qp/hub/passfd.so

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${PYTHON_CMD} setup.py install_demo_sites ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
