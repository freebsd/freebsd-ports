# $FreeBSD$

PORTNAME=	azure-cli
PORTVERSION=	2.0.59
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=2.0.55:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-profile>=2.1.2:sysutils/py-azure-cli-profile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-resource>=2.1.8:sysutils/py-azure-cli-resource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-monitor>=0.2.10:sysutils/py-azure-cli-monitor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-vm>=2.2.12:sysutils/py-azure-cli-vm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-telemetry>=1.0.1:sysutils/py-azure-cli-telemetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-storage>=2.3.1:sysutils/py-azure-cli-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-sql>=2.1.9:sysutils/py-azure-cli-sql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-sqlvm>=0.1.0:sysutils/py-azure-cli-sqlvm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-signalr>=1.0.0:sysutils/py-azure-cli-signalr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-servicefabric>=0.1.13:sysutils/py-azure-cli-servicefabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-servicebus>=0.3.3:sysutils/py-azure-cli-servicebus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-security>=0.1.0:sysutils/py-azure-cli-security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-search>=0.1.1:sysutils/py-azure-cli-search@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-role>=2.4.0:sysutils/py-azure-cli-role@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-reservations>=0.4.1:sysutils/py-azure-cli-reservations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-relay>=0.1.3:sysutils/py-azure-cli-relay@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-redis>=0.4.1:sysutils/py-azure-cli-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-rdbms>=0.3.7:sysutils/py-azure-cli-rdbms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-policyinsights>=0.1.1:sysutils/py-azure-cli-policyinsights@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-network>=2.3.3:sysutils/py-azure-cli-network@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-maps>=0.3.3:sysutils/py-azure-cli-maps@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-lab>=0.1.5:sysutils/py-azure-cli-lab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-kusto>=0.2.0:sysutils/py-azure-cli-kusto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-keyvault>=2.2.12:sysutils/py-azure-cli-keyvault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-iotcentral>=0.1.6:sysutils/py-azure-cli-iotcentral@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-iot>=0.3.6:sysutils/py-azure-cli-iot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-interactive>=0.4.1:sysutils/py-azure-cli-interactive@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-hdinsight>=0.3.1:sysutils/py-azure-cli-hdinsight@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-find>=0.2.13:sysutils/py-azure-cli-find@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-feedback>=2.1.4:sysutils/py-azure-cli-feedback@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-extension>=0.2.3:sysutils/py-azure-cli-extension@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-eventhubs>=0.3.3:sysutils/py-azure-cli-eventhubs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-eventgrid>=0.2.1:sysutils/py-azure-cli-eventgrid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-dms>=0.1.2:sysutils/py-azure-cli-dms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-dls>=0.1.8:sysutils/py-azure-cli-dls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-dla>=0.2.4:sysutils/py-azure-cli-dla@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-cosmosdb>=0.2.8:sysutils/py-azure-cli-cosmosdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-container>=0.3.14:sysutils/py-azure-cli-container@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-consumption>=0.4.2:sysutils/py-azure-cli-consumption@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-configure>=2.0.20:sysutils/py-azure-cli-configure@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-cognitiveservices>=0.2.4:sysutils/py-azure-cli-cognitiveservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-cloud>=2.1.0:sysutils/py-azure-cli-cloud@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-cdn>=0.2.0:sysutils/py-azure-cli-cdn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-botservice>=0.1.7:sysutils/py-azure-cli-botservice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-billing>=0.2.0:sysutils/py-azure-cli-billing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-batchai>=0.4.7:sysutils/py-azure-cli-batchai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-batch>=4.0.0:sysutils/py-azure-cli-batch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-backup>=1.2.1:sysutils/py-azure-cli-backup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-appservice>=0.2.14:sysutils/py-azure-cli-appservice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-ams>=0.4.2:sysutils/py-azure-cli-ams@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-advisor>=2.0.0:sysutils/py-azure-cli-advisor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-acs>=2.3.18:sysutils/py-azure-cli-acs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-acr>=2.2.1:sysutils/py-azure-cli-acr@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s#python#${PYTHON_CMD}#g" ${WRKSRC}/az

.include <bsd.port.mk>
