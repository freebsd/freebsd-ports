# New ports collection makefile for:	salt
# Date created:				2011-12-26
# Whom:					Christer Edwards <christer.edwards@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	salt
PORTVERSION=	0.10.2
CATEGORIES=	sysutils python
MASTER_SITES=	https://github.com/downloads/saltstack/salt/

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Distributed, remote execution and configuration management system

LICENSE=	AL2

LIB_DEPENDS=	zmq:${PORTSDIR}/devel/zmq
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.9:${PORTSDIR}/devel/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.1.9:${PORTSDIR}/devel/py-msgpack \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0:${PORTSDIR}/security/py-m2crypto

FETCH_ARGS=	-pRr
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

USE_RC_SUBR=	salt_master \
		salt_minion \
		salt_syndic

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

SUB_FILES=	pkg-message

MAN1=		salt-call.1 \
		salt-cp.1 \
		salt-key.1 \
		salt-master.1 \
		salt-minion.1 \
		salt-run.1 \
		salt-syndic.1 \
		salt.1

MAN7=		salt.7

post-patch:
.for file in conf/minion.template conf/master.template doc/man/salt-key.1 \
    doc/man/salt-cp.1 doc/man/salt-minion.1 doc/man/salt-syndic.1 \
    doc/man/salt-master.1 doc/man/salt-run.1 doc/man/salt.7 doc/man/salt.1 \
    salt/cli/__init__.py salt/__init__.py salt/config.py salt/client.py \
    salt/modules/mysql.py
	@${REINPLACE_CMD} -e 's|/etc/salt|${PREFIX}/etc/salt|' \
	    -e 's|/srv/salt|${PREFIX}/etc/salt/states|' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s|'install_requires|'data_files': [],'install_requires|" \
		${WRKSRC}/setup.py

post-install:
	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/master.template ${PREFIX}/etc/salt/master.sample
	${INSTALL_DATA} ${WRKSRC}/conf/minion.template ${PREFIX}/etc/salt/minion.sample
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/doc/man/,} ${MANPREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${MAN7} ${MANPREFIX}/man/man7/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
