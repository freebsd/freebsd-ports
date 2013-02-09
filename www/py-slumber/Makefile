# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	slumber
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python library that makes consuming a REST API easier

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests

OPTIONS_DEFINE=		YAML
YAML_DESC=		Enable YAML serializer support
OPTIONSFILE?=		${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MYAML}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml
.endif

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	dstufft
GH_COMMIT=	e5bde78
GH_TAGNAME=	v${DISTVERSION}

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
