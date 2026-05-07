PORTNAME=	azure-cli
PORTVERSION=	2.86.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	azure_cli-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools
WWW=		https://learn.microsoft.com/en-us/cli/azure/?view=azure-cli-latest \
		https://github.com/Azure/azure-cli/tree/dev/src/azure-cli \
		https://github.com/Azure/azure-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}antlr4-python3-runtime>=4.13.1,1:devel/py-antlr4-python3-runtime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-ai-projects>=1.0.0:devel/py-azure-ai-projects@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-appconfiguration>=1.7.2:devel/py-azure-appconfiguration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-batch>=15.0.0.b1:devel/py-azure-batch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=${PORTVERSION}<${PORTVERSION}_99:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cosmos>=3.0.2:devel/py-azure-cosmos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-data-tables>=12.4.0:devel/py-azure-data-tables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-datalake-store>=1.0.1<1.1:devel/py-azure-datalake-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault-administration>=4.4.0:devel/py-azure-keyvault-administration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault-certificates>=4.7.0:security/py-azure-keyvault-certificates@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault-keys>=4.11.0:security/py-azure-keyvault-keys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault-secrets>=4.7.0:security/py-azure-keyvault-secrets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault-securitydomain>=1.0.0.b1:devel/py-azure-keyvault-securitydomain@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-advisor>=9.0.0:devel/py-azure-mgmt-advisor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-apimanagement>=4.0.0:devel/py-azure-mgmt-apimanagement@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-appconfiguration>=6.0.0.b1:devel/py-azure-mgmt-appconfiguration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-appcontainers>=2.0.0:devel/py-azure-mgmt-appcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-applicationinsights>=1.0.0:devel/py-azure-mgmt-applicationinsights@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-authorization>=5.0.0.b1:devel/py-azure-mgmt-authorization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-batch>=17.3.0:devel/py-azure-mgmt-batch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-batchai>=7.0.0.b1:devel/py-azure-mgmt-batchai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-billing>=6.0.0:devel/py-azure-mgmt-billing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-botservice>=2.0.0.b3:devel/py-azure-mgmt-botservice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-cdn>=12.0.0:devel/py-azure-mgmt-cdn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-cognitiveservices>=15.0.0.b1:devel/py-azure-mgmt-cognitiveservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-compute34>=34.1.0:devel/py-azure-mgmt-compute34@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerinstance>=10.2.0.b1:devel/py-azure-mgmt-containerinstance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerregistry>=15.1.0.b1:devel/py-azure-mgmt-containerregistry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerregistrytasks>=1.0.0.b1:devel/py-azure-mgmt-containerregistrytasks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerservice>=41.1.0:devel/py-azure-mgmt-containerservice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-cosmosdb>=9.9.0,1:devel/py-azure-mgmt-cosmosdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-datalake-store>=1.1.0.b1:devel/py-azure-mgmt-datalake-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-datamigration>=10.0.0:devel/py-azure-mgmt-datamigration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-eventgrid>=10.2.0.b2:devel/py-azure-mgmt-eventgrid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-eventhub>=12.0.0.b1:devel/py-azure-mgmt-eventhub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-extendedlocation>=1.0.0.b2:devel/py-azure-mgmt-extendedlocation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-hdinsight>=9.1.0.b2:devel/py-azure-mgmt-hdinsight@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-imagebuilder>=1.3.0:devel/py-azure-mgmt-imagebuilder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-iotcentral>=10.0.0.b1:devel/py-azure-mgmt-iotcentral@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-iothub>=5.0.0.b1:devel/py-azure-mgmt-iothub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-iothubprovisioningservices>=1.1.0:devel/py-azure-mgmt-iothubprovisioningservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-keyvault>=13.0.0:devel/py-azure-mgmt-keyvault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-loganalytics>=13.0.0.b4:devel/py-azure-mgmt-loganalytics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-managementgroups>=1.0.0:devel/py-azure-mgmt-managementgroups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-maps>=2.0.0:devel/py-azure-mgmt-maps@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-marketplaceordering>=1.1.0:devel/py-azure-mgmt-marketplaceordering@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-media>=9.0:devel/py-azure-mgmt-media@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-monitor>=7.0.0.b1:devel/py-azure-mgmt-monitor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-msi>=7.1.0:devel/py-azure-mgmt-msi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-mysqlflexibleservers>=1.1.0.b2:devel/py-azure-mgmt-mysqlflexibleservers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-netapp>=10.1.0:devel/py-azure-mgmt-netapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-policyinsights>=1.1.0.b4:devel/py-azure-mgmt-policyinsights@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-postgresqlflexibleservers>=3.0.0.b1:devel/py-azure-mgmt-postgresqlflexibleservers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-privatedns>=1.0.0:devel/py-azure-mgmt-privatedns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-rdbms>=10.2.0.b17:devel/py-azure-mgmt-rdbms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-recoveryservices>=4.0.0:devel/py-azure-mgmt-recoveryservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-recoveryservicesbackup>=9.2.0:devel/py-azure-mgmt-recoveryservicesbackup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-redhatopenshift>=3.0.0:devel/py-azure-mgmt-redhatopenshift@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-redis>=14.5.0:devel/py-azure-mgmt-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource>=24.0.0:devel/py-azure-mgmt-resource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource-deployments>=1.0.0.b1:devel/py-azure-mgmt-resource-deployments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource-deploymentscripts>=1.0.0.b1:devel/py-azure-mgmt-resource-deploymentscripts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource-deploymentstacks>=1.0.0:devel/py-azure-mgmt-resource-deploymentstacks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource-templatespecs>=1.0.0.b1:devel/py-azure-mgmt-resource-templatespecs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-search>=9.0:devel/py-azure-mgmt-search@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-security>=6.0.0:devel/py-azure-mgmt-security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-servicebus>=10.0.0.b1:devel/py-azure-mgmt-servicebus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-servicefabric>=2.1.0:devel/py-azure-mgmt-servicefabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-servicefabricmanagedclusters>=2.1.0.b1:devel/py-azure-mgmt-servicefabricmanagedclusters@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-servicelinker>=1.2.0.b3:devel/py-azure-mgmt-servicelinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-signalr>=2.0.0.b2:devel/py-azure-mgmt-signalr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-sql>=4.0.0.b22:devel/py-azure-mgmt-sql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-sqlvirtualmachine>=1.0.0.b5:devel/py-azure-mgmt-sqlvirtualmachine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-storage>=24.0.0:devel/py-azure-mgmt-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-synapse>=2.1.0.b5:devel/py-azure-mgmt-synapse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-trafficmanager>=1.0.0:devel/py-azure-mgmt-trafficmanager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-web>=9.0.0:devel/py-azure-mgmt-web@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-monitor-query>=1.2.0:devel/py-azure-monitor-query@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=12.29.0.b1:devel/py-azure-storage-blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-common>=1.4:devel/py-azure-storage-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-file-datalake>=12.24.0.b1:devel/py-azure-storage-file-datalake@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-file-share>=12.25.0.b1:devel/py-azure-storage-file-share@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-queue>=12.16.0.b1:devel/py-azure-storage-queue@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-synapse-accesscontrol>=0.5.0:devel/py-azure-synapse-accesscontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-synapse-artifacts>=0.22.0:devel/py-azure-synapse-artifacts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-synapse-managedprivateendpoints>=0.4.0:devel/py-azure-synapse-managedprivateendpoints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-synapse-spark>=0.7.0:devel/py-azure-synapse-spark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=5.2.0,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.4<0.5:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fabric>=3.2.2,1<3.3,1:devel/py-fabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}javaproperties>=0.5.1<0.6:devel/py-javaproperties@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsondiff>=2.0.0<2.1:devel/py-jsondiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0.8<4.0.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycomposefile>=0.0.34:devel/py-pycomposefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyGithub>=1.38:devel/py-PyGithub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyNaCl>=1.5.0<1.7:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>=0.13.2:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=3.0<4:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sshtunnel>=0.1.4:net/py-sshtunnel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0,1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=1.8.0:www/py-websocket-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.12:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' ${WRKSRC}/az

.include <bsd.port.mk>
