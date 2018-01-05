# Created by: Guangyuan Yang <ygy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thefuck
DISTVERSION=	3.25
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	App that corrects your previous console command

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyte>0:devel/py-pyte@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist distutils noflavors
NO_ARCH=	yes

.include <bsd.port.mk>
