PORTNAME=	certbot-apache
PORTVERSION=	${ACME_VERSION}
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Apache plugin for Certbot
WWW=		https://certbot.eff.org/ \
		https://github.com/certbot/certbot \
		https://github.com/certbot/certbot/tree/master/certbot-apache

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${ACME_VERSION},1:security/py-acme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certbot>=${ACME_VERSION},1:security/py-certbot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-augeas>=0:textproc/py-python-augeas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=41.6.0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=1.3.1:devel/py-importlib-resources@${PY_FLAVOR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|apache2ctl|apachectl|' ${WRKSRC}/certbot_apache/_internal/configurator.py
	@${REINPLACE_CMD} -e 's|/etc/apache2|${LOCALBASE}/etc/apache24|' ${WRKSRC}/certbot_apache/_internal/configurator.py

.include "${.CURDIR}/../py-acme/version.mk"
.include <bsd.port.post.mk>
