# $FreeBSD$

PORTNAME=	certbot-apache
PORTVERSION=	${ACME_VERSION}
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Apache plugin for Certbot

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${ACME_VERSION},1:security/py-acme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certbot>=${ACME_VERSION},1:security/py-certbot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-augeas>0:textproc/py-python-augeas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|apache2ctl|apachectl|' ${WRKSRC}/certbot_apache/_internal/configurator.py
	@${REINPLACE_CMD} -e 's|/etc/apache2|${LOCALBASE}/etc/apache24|' \
	${WRKSRC}/certbot_apache/_internal/configurator.py

.include "${.CURDIR}/../py-acme/version.mk"
.include <bsd.port.mk>
