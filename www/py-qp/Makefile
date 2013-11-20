# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	qp
PORTVERSION=	2.2
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

MAKE_ENV=	USE_DISTUTILS=yes
USE_PYDISTUTILS=yes
USE_PYTHON=	-2.7

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES.txt LICENSE.txt README.txt ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/ && ${PYTHON_CMD} ${PYSETUP} install_demo_sites ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
