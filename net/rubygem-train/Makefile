# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	train
PORTVERSION=	3.8.6
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Transport interface to talk to different backends

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=6.0.3.1:devel/rubygem-activesupport60 \
		rubygem-azure_graph_rbac>=0.16<1:devel/rubygem-azure_graph_rbac \
		rubygem-azure_mgmt_key_vault>=0.17<1:devel/rubygem-azure_mgmt_key_vault \
		rubygem-azure_mgmt_resources>=0.15<1:devel/rubygem-azure_mgmt_resources \
		rubygem-azure_mgmt_security>=0.18<1:devel/rubygem-azure_mgmt_security \
		rubygem-azure_mgmt_storage>=0.18<1:devel/rubygem-azure_mgmt_storage \
		rubygem-docker-api>=1.26<3.0:net/rubygem-docker-api \
		rubygem-google-api-client>=0.23.9:devel/rubygem-google-api-client \
		rubygem-googleauth>=0.6.6:security/rubygem-googleauth \
		rubygem-inifile>=3.0<4:textproc/rubygem-inifile \
		rubygem-train-core>=${PORTVERSION}:net/rubygem-train-core \
		rubygem-train-winrm>=0.2<1:net/rubygem-train-winrm

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
