PORTNAME=	splunk-hec
PORTVERSION=	1.81
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Python class to submit events to Splunk HTTP Event Collector
WWW=		https://github.com/georgestarcher/Splunk-Class-httpevent

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	georgestarcher
GH_PROJECT=	Splunk-Class-httpevent
GH_TAGNAME=	b1b7aae37bc73ea6e89c4a4667c4d8d227804546

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
