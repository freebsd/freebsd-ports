# $FreeBSD$

PORTNAME=	azure-cli
PORTVERSION=	2.5.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}antlr4-python3-runtime>=0:devel/py-antlr4-python3-runtime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-batch>=9.0:devel/py-azure-batch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=${PORTVERSION}:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-telemetry>=1.0.2<2.0:sysutils/py-azure-cli-telemetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cosmos>=3.0.2:devel/py-azure-cosmos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-datalake-store>=0.0.48:devel/py-azure-datalake-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-functions-devops-build>=0.0.22:devel/py-azure-functions-devops-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-graphrbac>=0.60.0:devel/py-azure-graphrbac@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault>=1.1:devel/py-azure-keyvault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-advisor>=2.0.1:devel/py-azure-mgmt-advisor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-apimanagement>=0.1.0:devel/py-azure-mgmt-apimanagement@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-applicationinsights>=0.1.1:devel/py-azure-mgmt-applicationinsights@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-appconfiguration>=0.4.0:devel/py-azure-mgmt-appconfiguration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-authorization>=0.52.0:devel/py-azure-mgmt-authorization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-batch>=7.0:devel/py-azure-mgmt-batch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-batchai>=2.0:devel/py-azure-mgmt-batchai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-billing>=0.2:devel/py-azure-mgmt-billing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-botservice>=0.2.0:devel/py-azure-mgmt-botservice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-cdn>=4.0.0.r1:devel/py-azure-mgmt-cdn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-cognitiveservices>=5.0.0:devel/py-azure-mgmt-cognitiveservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-compute>=12.0:devel/py-azure-mgmt-compute@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-consumption>=2.0:devel/py-azure-mgmt-consumption@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerinstance>=1.4:devel/py-azure-mgmt-containerinstance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerregistry>=3.0.0.r11:devel/py-azure-mgmt-containerregistry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerservice>=9.0.1:devel/py-azure-mgmt-containerservice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-core>=0:devel/py-azure-mgmt-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-cosmosdb>=0.13.0:devel/py-azure-mgmt-cosmosdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-datalake-analytics>=0.2.1:devel/py-azure-mgmt-datalake-analytics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-datalake-store>=0.5.0:devel/py-azure-mgmt-datalake-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-datamigration>=0.1.0:devel/py-azure-mgmt-datamigration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-deploymentmanager>=0.2.0:devel/py-azure-mgmt-deploymentmanager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-devtestlabs>=2.2:devel/py-azure-mgmt-devtestlabs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-dns>=2.1:devel/py-azure-mgmt-dns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-eventgrid>=2.2:devel/py-azure-mgmt-eventgrid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-eventhub>=3.0.0:devel/py-azure-mgmt-eventhub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-hdinsight>=1.4.0:devel/py-azure-mgmt-hdinsight@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-imagebuilder>=0.2.1:devel/py-azure-mgmt-imagebuilder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-iotcentral>=3.0.0:devel/py-azure-mgmt-iotcentral@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-iothub>=0.11.0:devel/py-azure-mgmt-iothub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-iothubprovisioningservices>=0.2.0:devel/py-azure-mgmt-iothubprovisioningservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-keyvault>=2.2.0:devel/py-azure-mgmt-keyvault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-kusto>=0.3.0:devel/py-azure-mgmt-kusto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-loganalytics>=0.5.0:devel/py-azure-mgmt-loganalytics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-managedservices>=1.0:devel/py-azure-mgmt-managedservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-managementgroups>=0.1:devel/py-azure-mgmt-managementgroups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-maps>=0.1.0:devel/py-azure-mgmt-maps@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-marketplaceordering>=0.1:devel/py-azure-mgmt-marketplaceordering@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-media>=1.1:devel/py-azure-mgmt-media@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-monitor>=0.9.0:devel/py-azure-mgmt-monitor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-msi>=0.2:devel/py-azure-mgmt-msi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-network>=10.1.0:devel/py-azure-mgmt-network@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-netapp>=0.8.0:devel/py-azure-mgmt-netapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-policyinsights>=0.4.0:devel/py-azure-mgmt-policyinsights@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-privatedns>=0.1.0:devel/py-azure-mgmt-privatedns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-rdbms>=2.2.0:devel/py-azure-mgmt-rdbms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-recoveryservices>=0.4.0:devel/py-azure-mgmt-recoveryservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-recoveryservicesbackup>=0.6.0:devel/py-azure-mgmt-recoveryservicesbackup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-redhatopenshift>=0.1.0:devel/py-azure-mgmt-redhatopenshift@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-redis>=7.0.0.r1:devel/py-azure-mgmt-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-relay>=0.1.0:devel/py-azure-mgmt-relay@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-reservations>=0.6.0:devel/py-azure-mgmt-reservations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource>=9.0.0:devel/py-azure-mgmt-resource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-search>=2.0:devel/py-azure-mgmt-search@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-security>=0.1.0:devel/py-azure-mgmt-security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-servicebus>=0.6.0:devel/py-azure-mgmt-servicebus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-servicefabric>=0.4.0:devel/py-azure-mgmt-servicefabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-signalr>=0.3.0:devel/py-azure-mgmt-signalr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-sql>=0.18.0:devel/py-azure-mgmt-sql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-sqlvirtualmachine>=0.5.0:devel/py-azure-mgmt-sqlvirtualmachine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-storage>=9.0.0:devel/py-azure-mgmt-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-trafficmanager>=0.51.0:devel/py-azure-mgmt-trafficmanager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-web>=0.44.0:devel/py-azure-mgmt-web@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-multiapi-storage>=0.3.1:devel/py-azure-multiapi-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=1.3.1:devel/py-azure-storage-blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.1:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.3.1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fabric>=2.4:devel/py-fabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsmin>=2.2.2:devel/py-jsmin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}knack>=0.7.0.r3:devel/py-knack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0.8:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.4:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=17.1.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2019.1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>=0.13.2:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sshtunnel>=0.1.4:net/py-sshtunnel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.18:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vsts-cd-manager>=1.0.2:devel/py-vsts-cd-manager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0.56.0:www/py-websocket-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.12:devel/py-xmltodict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}javaproperties>=0.5.1:devel/py-javaproperties@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsondiff>=1.2.0:devel/py-jsondiff@${PY_FLAVOR}

USES=		azurepy python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s#python#${PYTHON_CMD}#g" ${WRKSRC}/az

.include <bsd.port.mk>
