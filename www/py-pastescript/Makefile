# Created by: Dryice Liu	<dryice@dryice.name>
# $FreeBSD$

PORTNAME=	PasteScript
PORTVERSION=	2.0.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Pluggable command-line frontend

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.0.1:devel/py-cheetah@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flup>0:www/py-flup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=1.7.2:www/py-paste@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.3.2:www/py-pastedeploy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsgiutils>0:devel/py-wsgiutils@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-extract:
		${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
