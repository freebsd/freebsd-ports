# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requests-oauthlib
PORTVERSION=	0.3.2
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	OAuthlib authentication support for Requests

LICENSE=	ISCL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauthlib>=0.4.2:${PORTSDIR}/security/py-oauthlib \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

USE_GITHUB=	yes
GH_ACCOUNT=	requests
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	0b1fe5c

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

NO_STAGE=	yes
.include <bsd.port.mk>
