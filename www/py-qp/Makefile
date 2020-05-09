# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	qp
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/qp/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python web framework to use qpy and durus together

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}durus>=0:devel/py-durus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qpy>=1.7:www/py-qpy@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		python:2.7
USE_PYTHON=	distutils

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
