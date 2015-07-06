# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	salt
PORTVERSION=	2015.5.2
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Distributed remote execution and configuration management system

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.1.13:${PORTSDIR}/devel/py-msgpack \
		${PYTHON_PKGNAMEPREFIX}libcloud>=0.14.0:${PORTSDIR}/net/py-libcloud \
		${PYTHON_PKGNAMEPREFIX}botocore>0:${PORTSDIR}/devel/py-botocore \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>0:${PORTSDIR}/textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}requests>1:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}enum34>0:${PORTSDIR}/devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}progressbar>0:${PORTSDIR}/misc/py-progressbar

OPTIONS_DEFINE=	ZEROMQ RAET
OPTIONS_DEFAULT=	ZEROMQ

ZEROMQ_DESC=	Enable ZeroMQ transport
RAET_DESC=	Enable RAET transport

ZEROMQ_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:${PORTSDIR}/net/py-pyzmq
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:${PORTSDIR}/net/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:${PORTSDIR}/security/py-m2crypto \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto

RAET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libnacl>=1.4.2:${PORTSDIR}/security/py-libnacl \
		${PYTHON_PKGNAMEPREFIX}ioflo>=1.2.1:${PORTSDIR}/devel/py-ioflo \
		${PYTHON_PKGNAMEPREFIX}raet>0:${PORTSDIR}/net/py-raet

USES=		python:2
USE_PYTHON=	distutils
PYDISTUTILS_EGGINFO=	salt-${DISTVERSION}-py${PYTHON_VER}.egg-info

PYDISTUTILS_INSTALLARGS+=\
		--prefix=${PREFIX} \
		--salt-root-dir=/ \
		--salt-config-dir=${ETCDIR} \
		--salt-cache-dir=/var/cache/salt \
		--salt-sock-dir=/var/run/salt \
		--salt-srv-root-dir=${ETCDIR} \
		--salt-base-file-roots-dir=${ETCDIR}/states \
		--salt-base-pillar-roots-dir=${ETCDIR}/pillar \
		--salt-base-master-roots-dir=${ETCDIR}/salt-master \
		--salt-logs-dir=/var/log/salt \
		--salt-pidfile-dir=/var/run

USE_RC_SUBR=	salt_master \
		salt_minion \
		salt_syndic

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

SUB_FILES=	pkg-message

post-patch:
.for file in conf/minion conf/master doc/man/salt-key.1 \
	doc/man/salt-cp.1 doc/man/salt-minion.1 doc/man/salt-syndic.1 \
	doc/man/salt-master.1 doc/man/salt-run.1 doc/man/salt.7 doc/man/salt.1 \
	doc/man/salt-call.1 salt/config.py \
	salt/modules/mysql.py salt/utils/parsers.py salt/modules/tls.py \
	salt/modules/postgres.py salt/utils/migrations.py
	@${REINPLACE_CMD} -e 's|/etc/salt|${ETCDIR}|' \
		-e 's|/srv/salt|${ETCDIR}/states|' \
		-e 's|/srv/pillar|${ETCDIR}/pillar|' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|yumpkg5|pkgng|' ${WRKSRC}/conf/minion

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/master ${STAGEDIR}${ETCDIR}/master.sample
	${INSTALL_DATA} ${WRKSRC}/conf/minion ${STAGEDIR}${ETCDIR}/minion.sample

.include <bsd.port.mk>
