PORTNAME=	train
PORTVERSION=	3.12.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Transport interface to talk to different backends
WWW=		https://github.com/inspec/train

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=6.0.3.1:devel/rubygem-activesupport60 \
		rubygem-azure_graph_rbac>=0.16<1:devel/rubygem-azure_graph_rbac \
		rubygem-azure_mgmt_key_vault>=0.17<1:devel/rubygem-azure_mgmt_key_vault \
		rubygem-azure_mgmt_resources>=0.15<1:devel/rubygem-azure_mgmt_resources \
		rubygem-azure_mgmt_security>=0.18<1:devel/rubygem-azure_mgmt_security \
		rubygem-azure_mgmt_storage>=0.18<1:devel/rubygem-azure_mgmt_storage \
		rubygem-docker-api>=1.26<3.0:net/rubygem-docker-api \
		rubygem-google-apis-admin_directory_v1>=0.46.0<1:devel/rubygem-google-apis-admin_directory_v1 \
		rubygem-google-apis-cloudkms_v1>=0.41.0<1:devel/rubygem-google-apis-cloudkms_v1 \
		rubygem-google-apis-cloudresourcemanager_v1035>=0.35.0<0.36:devel/rubygem-google-apis-cloudresourcemanager_v1035 \
		rubygem-google-apis-compute_v1>=0.83.0<1:devel/rubygem-google-apis-compute_v1 \
		rubygem-google-apis-iam_v1050>=0.50.0<0.51:devel/rubygem-google-apis-iam_v1050 \
		rubygem-google-apis-monitoring_v3>=0.51.0<1:devel/rubygem-google-apis-monitoring_v3 \
		rubygem-google-apis-storage_v1>=0.30.0<1:devel/rubygem-google-apis-storage_v1 \
		rubygem-googleauth>=0.16.2<2.0:security/rubygem-googleauth \
		rubygem-inifile>=3.0<4:textproc/rubygem-inifile \
		rubygem-train-core>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-train-core \
		rubygem-train-winrm>=0.2<1:net/rubygem-train-winrm

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
