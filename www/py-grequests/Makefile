# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grequests
PORTVERSION=	0.2.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Requests with Gevent to make asyncronous HTTP requests

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>0:${PORTSDIR}/devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:${PORTSDIR}/www/py-requests

USE_GITHUB=	yes
GH_ACCOUNT=	kennethreitz
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	aee3be6

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

NO_STAGE=	yes
.include <bsd.port.mk>
