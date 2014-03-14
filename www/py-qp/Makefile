# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	qp
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/qp/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python web framework to use qpy and durus together

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}durus>=0:${PORTSDIR}/devel/py-durus \
		${PYTHON_PKGNAMEPREFIX}qpy>=1.7:${PORTSDIR}/www/py-qpy
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_PYDISTUTILS=yes
USE_PYTHON=	2

SUB_FILES=	pkg-message

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt
PORTEXAMPLES=	*

post-build:
	@${STRIP_CMD} ${WRKSRC}/build/lib.*/qp/hub/passfd.so

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${PYTHON_CMD} ${PYSETUP} install_demo_sites ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
