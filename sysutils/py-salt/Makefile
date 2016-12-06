# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	salt
PORTVERSION=	2016.11.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Distributed remote execution and configuration management system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.1.13:devel/py-msgpack-python \
		${PYTHON_PKGNAMEPREFIX}libcloud>=0.14.0:net/py-libcloud \
		${PYTHON_PKGNAMEPREFIX}botocore>0:devel/py-botocore \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>0:textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}requests>1:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}progressbar>0:misc/py-progressbar \
		${PYTHON_PKGNAMEPREFIX}futures>=2.0:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.2.1:www/py-tornado

OPTIONS_DEFINE=	ZEROMQ RAET
OPTIONS_DEFAULT=	ZEROMQ

ZEROMQ_DESC=	Enable ZeroMQ transport
RAET_DESC=	Enable RAET transport

ZEROMQ_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:net/py-pyzmq
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:net/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}pycrypto>2.6.1:security/py-pycrypto

RAET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libnacl>=1.4.2:security/py-libnacl \
		${PYTHON_PKGNAMEPREFIX}ioflo>=1.2.1:devel/py-ioflo \
		${PYTHON_PKGNAMEPREFIX}raet>0:net/py-raet

USES=		cpe python:2
CPE_VENDOR=	saltstack
CPE_PRODUCT=	salt
USE_PYTHON=	distutils
NO_ARCH=	yes
PYDISTUTILS_EGGINFO=	salt-${DISTVERSION}-py${PYTHON_VER}.egg-info

USE_RC_SUBR=	salt_api \
		salt_proxy \
		salt_master \
		salt_minion \
		salt_syndic

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

SUB_FILES=	pkg-message

post-patch:
.for file in conf/minion conf/master doc/man/salt-key.1 \
	doc/man/salt-cp.1 doc/man/salt-minion.1 doc/man/salt-syndic.1 \
	doc/man/salt-master.1 doc/man/salt-run.1 doc/man/salt.7 doc/man/salt.1 \
	doc/man/salt-call.1 \
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
