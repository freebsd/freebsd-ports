PORTNAME=	salt
PORTVERSION=	3008.1
PORTEPOCH=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Distributed remote execution and configuration management system
WWW=		https://pypi.org/project/salt/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PATCH_SITES=    https://github.com/saltstack/salt/pull/
PATCHFILES+=    69710.patch:-p1

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}looseversion>0:devel/py-looseversion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR}


RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.5.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcloud>=0.14.0:net/py-libcloud@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.3:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0.3.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}looseversion>0:devel/py-looseversion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter>0:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozenlist>0:devel/py-frozenlist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timelib>0:devel/py-timelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.text>=4.0.0:devel/py-jaraco.text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.functools>0:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.context>0:devel/py-jaraco.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycparser>0:devel/py-pycparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gnupg>0:security/py-gnupg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}truststore>0:security/py-truststore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>0:devel/py-xxhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipp>0:devel/py-zipp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp-proto-http>0:devel/py-opentelemetry-exporter-otlp-proto-http@${PY_FLAVOR}


USES=		cpe python

CPE_VENDOR=	saltstack
CPE_PRODUCT=	salt
USE_PYTHON=	autoplist cryptography pep517
NO_ARCH=	yes

CONFLICTS=	py[0-9]*-salt-300*

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

OPTIONS_DEFINE=	AWS BASH FISH TCP ZEROMQ ZSH
OPTIONS_DEFAULT=	BASH FISH ZEROMQ ZSH

AWS_DESC=	Install dependencies required for Amazon Web Services
TCP_DESC=	Install dependencies required for TCP transport
ZEROMQ_DESC=	Install dependencies required for ZeroMQ transport

# AWS dependencies (Note: the devel/py-botocore port is updated very frequently)
AWS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}botocore>0:devel/py-botocore@${PY_FLAVOR}

TCP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodomex>=3.9.7:security/py-pycryptodomex@${PY_FLAVOR}

ZEROMQ_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:net/py-pyzmq@${PY_FLAVOR}
ZEROMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:net/py-pyzmq@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycryptodomex>=3.9.7:security/py-pycryptodomex@${PY_FLAVOR}

BASH_PLIST_FILES=	share/bash-completion/completions/salt
FISH_PLIST_FILES=	share/fish/completions/salt-call.fish \
					share/fish/completions/salt-cp.fish \
					share/fish/completions/salt-key.fish \
					share/fish/completions/salt-master.fish \
					share/fish/completions/salt-minion.fish \
					share/fish/completions/salt-run.fish \
					share/fish/completions/salt-syndic.fish \
					share/fish/completions/salt.fish \
					share/fish/completions/salt_common.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_salt

post-patch:
.for file in conf/minion conf/master doc/man/salt-key.1 \
	doc/man/salt-cp.1 doc/man/salt-minion.1 doc/man/salt-syndic.1 \
	doc/man/salt-master.1 doc/man/salt-run.1 doc/man/salt.1 \
	doc/man/salt-call.1 salt/modules/mysql.py salt/modules/tls.py salt/modules/postgres.py
	@${REINPLACE_CMD} -e 's|/etc/salt|${ETCDIR}|' \
		-e 's|/srv/salt|${ETCDIR}/states|' \
		-e 's|/srv/pillar|${ETCDIR}/pillar|' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|yumpkg5|pkgng|' ${WRKSRC}/conf/minion
	@${REINPLACE_CMD} -e 's|"/usr/bin/python3"|"${PYTHON_CMD}"|' ${WRKSRC}/salt/auth/pam.py

do-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKSRC}/pkg/rpm/salt.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/salt

do-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions/
	${INSTALL_DATA} ${WRKSRC}/pkg/common/fish-completions/*.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions

do-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/pkg/common/salt.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_salt

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/master ${STAGEDIR}${ETCDIR}/master.sample
	${INSTALL_DATA} ${WRKSRC}/conf/minion ${STAGEDIR}${ETCDIR}/minion.sample

.include <bsd.port.mk>
