PORTNAME=	postfix-mta-sts-resolver
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	TLS client policy for Postfix according to domain MTA-STS policy
WWW=		https://pypi.python.org/pypi/postfix-mta-sts-resolver

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}aiodns>=3.0.0:dns/py-aiodns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.4.4:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.12:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	Snawoot
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	mta_sts

NO_ARCH=	yes

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
PLIST_FILES=	"@sample etc/mta-sts-daemon.yml.sample"

OPTIONS_DEFINE=		PGSQL REDIS SQLITE UVLOOP
OPTIONS_DEFAULT=	PGSQL REDIS SQLITE UVLOOP

UVLOOP_DESC=		Event loop support
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asyncpg>=0.27.0:databases/py-asyncpg@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=4.2.0:databases/py-redis@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>=0.10.0:databases/py-aiosqlite@${PY_FLAVOR}
UVLOOP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uvloop>=0.11.0:devel/py-uvloop@${PY_FLAVOR}

post-extract:
	${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|' \
		${WRKSRC}/postfix_mta_sts_resolver/defaults.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/config_examples/mta-sts-daemon.yml.internal \
			${STAGEDIR}${PREFIX}/etc/mta-sts-daemon.yml.sample

.include <bsd.port.mk>
