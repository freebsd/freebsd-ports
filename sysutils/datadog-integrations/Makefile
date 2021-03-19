# $FreeBSD$

PORTNAME=	datadog-integrations
DISTVERSION=	7.24.0
CATEGORIES=	sysutils

MAINTAINER=	uros@gruber.si
COMMENT=	Datadog Agent Integrations

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

RUN_DEPENDS=	datadog-agent>=7.24.1:sysutils/datadog-agent \
		${PYTHON_PKGNAMEPREFIX}botocore>0:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-unixsocket>0:www/py-requests-unixsocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uptime>0:sysutils/py-uptime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	DataDog
GH_PROJECT=	integrations-core

ETCDIR=		${PREFIX}/etc/datadog

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		datadog
GROUPS=		${USERS}

PLIST_SUB+=	USER=${USERS} \
		GROUP=${GROUPS}

OPTIONS_DEFINE=	APACHE CONSUL COREDNS DIRECTORY DISK DNS MYSQL NETWORK NGINX PHP POSTFIX PROCESS REDIS SSH SYS_CORE SYS_SWAP TCP TLS

OPTIONS_SUB=	yes

APACHE_DESC=	Apache check integration
CONSUL_DESC=	Consul check integration
COREDNS_DESC=	CoreDNS check integration
DIRECTORY_DESC=	Directory check integration
DISK_DESC=	Disk check integration
DNS_DESC=	DNS check integration
MYSQL_DESC=	MySQL check integration
NETWORK_DESC=	Network check integration
NGINX_DESC=	Nginx check integration
PHP_DESC=	PHP-fpm check integration
POSTFIX_DESC=	Postfix check integration
PROCESS_DESC=	Process check integration
REDIS_DESC=	Redis check integration
SSH_DESC=	SSH check integration
SYS_CORE_DESC=	System Core check integration
SYS_SWAP_DESC=	System Swap check integration
TCP_DESC=	TCP check integration
TLS_DESC=	TLS check integration

APACHE_VARS=	integrations+=apache conffiles+=apache
CONSUL_VARS=	integrations+=consul conffiles+=consul
COREDNS_VARS=	integrations+=coredns conffiles+=coredns
DIRECTORY_VARS=	integrations+=directory conffiles+=directory
DISK_VARS=	integrations+=disk conffiles+=disk
DNS_VARS=	integrations+=dns_check conffiles+=dns_check
MYSQL_VARS=	integrations+=mysql conffiles+=mysql
NETWORK_VARS=	integrations+=network conffiles+=network
NGINX_VARS=	integrations+=nginx conffiles+=nginx
PHP_VARS=	integrations+=php_fpm conffiles+=php_fpm
POSTFIX_VARS=	integrations+=postfix conffiles+=postfix
PROCESS_VARS=	integrations+=process conffiles+=process
REDIS_VARS=	integrations+=redisdb conffiles+=redisdb
SSH_VARS=	integrations+=ssh_check conffiles+=ssh_check
SYS_CORE_VARS=	integrations+=system_core conffiles+=system_core
SYS_SWAP_VARS=	integrations+=system_swap conffiles+=system_swap
TCP_VARS=	integrations+=tcp_check conffiles+=tcp_check
TLS_VARS=	integrations+=tls conffiles+=tls

# find integrations-core -name setup.py | awk -F\/ '{print $2}' | sort | uniq | grep -v datadog_checks_dev | tr '\n' ' '
INTEGRATIONS=	datadog_checks_base

# find integrations-core -name conf.yaml.example | awk -F\/ '{print $2}' | sort | uniq | grep -v datadog_checks_dev | tr '\n' ' '
CONFFILES=

DIRECTORY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scandir>0:sysutils/py-scandir@${PY_FLAVOR}
DISK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}
DNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR}
NETWORK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}
PHP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flup6>0:www/py-flup6@${PY_FLAVOR}
PROCESS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis
SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR}
SYS_CORE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}
SYS_SWAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}
TLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}service_identity>0:security/py-service_identity@${PY_FLAVOR}

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d

# Install core-integrations
.for dir in ${INTEGRATIONS}
	(cd ${WRKSRC}/${dir}; \
	${PYTHON_CMD} setup.py bdist; \
	${TAR} -xzf dist/*.tar.gz -C ${STAGEDIR})
.endfor

post-install:
# Install core-integrations
.for dir in ${CONFFILES}
	(cd ${WRKSRC}/${dir}; \
	${MV} datadog_checks/${dir}/data ${STAGEDIR}${ETCDIR}/conf.d/${dir}.d)
.endfor

.include <bsd.port.mk>
