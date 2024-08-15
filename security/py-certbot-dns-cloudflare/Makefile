PORTNAME=	certbot-dns-cloudflare
PORTVERSION=	${ACME_VERSION}
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/certbot/certbot/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	certbot_dns_cloudflare-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Cloudflare DNS plugin for Certbot
WWW=		https://certbot.eff.org/ \
		https://github.com/certbot/certbot \
		https://github.com/certbot/certbot/tree/master/certbot-dns-cloudflare

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${ACME_VERSION},1:security/py-acme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certbot>=${ACME_VERSION},1:security/py-certbot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudflare>=1.5.1<2.20_99:dns/py-cloudflare@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=41.6.0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include "${.CURDIR}/../py-acme/version.mk"
.include <bsd.port.mk>
