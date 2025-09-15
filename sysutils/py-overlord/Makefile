PORTNAME=	overlord
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.2
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Deploy FreeBSD jails as fast as you code
WWW=		https://github.com/DtxdF/${PORTNAME}

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>=0:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiostalk>=0:net/py-aiostalk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asciitree>=0:graphics/py-asciitree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}etcd3gw>=0:devel/py-etcd3gw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx-retries>=0:www/py-httpx-retries@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanfriendly>=0:textproc/py-humanfriendly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ifaddr>=0:net/py-ifaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml-env>=0:devel/py-pyaml-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymemcache>=0:databases/py-pymemcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}supervisor>=0:sysutils/py-supervisor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sysctl>=0:devel/py-sysctl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR} \
		beanstalkd>=0:net/beanstalkd \
		memcached>=0:databases/memcached

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
USE_PYTHON=	distutils

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_PKGNAMEPREFIX=${PYTHON_PKGNAMEPREFIX}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/.overlord.yml ${STAGEDIR}${PREFIX}/etc/overlord.yml.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/supervisord/supervisord.d/overlord.ini ${STAGEDIR}${DATADIR}/overlord.ini
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-libexec
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-manpages
	@${MKDIR} ${STAGEDIR}/var/log/overlord

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
