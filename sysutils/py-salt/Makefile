# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	salt
PORTVERSION=	0.17.1
PORTREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Distributed remote execution and configuration management system

LICENSE=	AL2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.9:${PORTSDIR}/devel/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.1.9:${PORTSDIR}/devel/py-msgpack \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0:${PORTSDIR}/security/py-m2crypto \
		sshpass>=0:${PORTSDIR}/security/sshpass
RUN_DEPENDS:=	${BUILD_DEPENDS}

FETCH_ARGS=	-pRr
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

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
	@${REINPLACE_CMD} -e 's|/etc/salt|${PREFIX}/etc/salt|' \
		-e 's|/srv/salt|${PREFIX}/etc/salt/states|' \
		-e 's|/srv/pillar|${PREFIX}/etc/salt/pillar|' ${WRKSRC}/${file}
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/master ${STAGEDIR}${ETCDIR}/master.sample
	${INSTALL_DATA} ${WRKSRC}/conf/minion ${STAGEDIR}${ETCDIR}/minion.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
