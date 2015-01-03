# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	slumber
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python library that makes consuming a RESTful API easier

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=		YAML

YAML_DESC=		Enable YAML serializer support
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml

USE_GITHUB=	yes
GH_ACCOUNT=	dstufft
GH_COMMIT=	85b17b9
GH_TAGNAME=	v${DISTVERSION}

USES=		python
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
