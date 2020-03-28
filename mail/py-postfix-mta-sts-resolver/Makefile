# $FreeBSD$

PORTNAME=	postfix-mta-sts-resolver
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=v
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	TLS client policy for Postfix according to domain MTA-STS policy

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>=1.1.1:dns/py-aiodns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.4.4:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.12:devel/py-yaml@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		python:3.5+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	Snawoot

OPTIONS_DEFINE=	REDIS SQLITE

REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aioredis>=1.2.0:databases/py-aioredis@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>=1.10.0:databases/py-aiosqlite@${PY_FLAVOR}

USE_RC_SUBR=	mta_sts

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
PLIST_FILES=	"@sample etc/mta-sts-daemon.yml.sample"

post-extract:
	${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|' \
		${WRKSRC}/postfix_mta_sts_resolver/defaults.py

post-install:
	${CP} ${WRKSRC}/config_examples/mta-sts-daemon.yml.internal ${STAGEDIR}${PREFIX}/etc/mta-sts-daemon.yml.sample

.include <bsd.port.mk>
