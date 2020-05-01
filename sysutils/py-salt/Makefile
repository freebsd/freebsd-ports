# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	salt
PORTVERSION=	2019.2.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Distributed remote execution and configuration management system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>0:textproc/py-MarkupSafe@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PY_FUTURES} \
		${PYTHON_PKGNAMEPREFIX}libcloud>=0.14.0:net/py-libcloud@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.3:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}progressbar>0:misc/py-progressbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0.3.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado4>=4.2.1:www/py-tornado4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR}

USES=		cpe python:3.6-3.7

CPE_VENDOR=	saltstack
CPE_PRODUCT=	salt
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

# we must pass these options before the target name, and python.mk has no
# early-arguments variable, so we have to manipulate the target
PYDISTUTILS_INSTALL_TARGET=\
	--salt-root-dir=/ \
	--salt-config-dir=${ETCDIR} \
	--salt-cache-dir=/var/cache/salt \
	--salt-sock-dir=/var/run/salt \
	--salt-srv-root-dir=${ETCDIR} \
	--salt-base-file-roots-dir=${ETCDIR}/states \
	--salt-base-pillar-roots-dir=${ETCDIR}/pillar \
	--salt-base-master-roots-dir=${ETCDIR}/salt-master \
	--salt-logs-dir=/var/log/salt \
	--salt-pidfile-dir=/var/run \
	install

USE_RC_SUBR=	salt_api \
		salt_master \
		salt_minion \
		salt_proxy \
		salt_syndic

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	AWS RAET TCP ZEROMQ
OPTIONS_DEFAULT=ZEROMQ

AWS_DESC=	Install dependencies required for Amazon Web Services
RAET_DESC=	Install dependencies required for RAET transport
TCP_DESC=	Install dependencies required for TCP transport
ZEROMQ_DESC=	Install dependencies required for ZeroMQ transport

# AWS dependencies (Note: the devel/py-botocore port is updated very frequently)
AWS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}boto>=2.32.1:devel/py-boto@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}botocore>0:devel/py-botocore@${PY_FLAVOR}

RAET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libnacl>=1.0.0:security/py-libnacl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ioflo>=1.1.7:devel/py-ioflo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}raet>=0.6.0:net/py-raet@${PY_FLAVOR}

TCP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:security/py-pycrypto@${PY_FLAVOR}

ZEROMQ_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:net/py-pyzmq@${PY_FLAVOR}
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:net/py-pyzmq@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:security/py-pycrypto@${PY_FLAVOR}

post-patch:
.for file in conf/minion conf/master doc/man/salt-key.1 \
	doc/man/salt-cp.1 doc/man/salt-minion.1 doc/man/salt-syndic.1 \
	doc/man/salt-master.1 doc/man/salt-run.1 doc/man/salt.7 doc/man/salt.1 \
	doc/man/salt-call.1 salt/modules/mysql.py salt/modules/tls.py salt/modules/postgres.py
	@${REINPLACE_CMD} -e 's|/etc/salt|${ETCDIR}|' \
		-e 's|/srv/salt|${ETCDIR}/states|' \
		-e 's|/srv/pillar|${ETCDIR}/pillar|' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|yumpkg5|pkgng|' ${WRKSRC}/conf/minion
	@${REINPLACE_CMD} -e 's|msgpack-python|msgpack|' ${WRKSRC}/requirements/base.txt

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/master ${STAGEDIR}${ETCDIR}/master.sample
	${INSTALL_DATA} ${WRKSRC}/conf/minion ${STAGEDIR}${ETCDIR}/minion.sample

.include <bsd.port.mk>
