PORTNAME=	gitlab-fog-azure-rm
PORTVERSION=	1.3.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Stripped-down fork that enables Azure Blob Storage

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-azure-storage-blob>=2.0<3:devel/rubygem-azure-storage-blob \
		rubygem-azure-storage-common>=2.0<3:devel/rubygem-azure-storage-common \
		rubygem-fog-core210>=2.1.0<2.1.1:devel/rubygem-fog-core210 \
		rubygem-fog-json>=1.2.0<1.3:devel/rubygem-fog-json \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-ms_rest_azure>=0.12.0<0.13:devel/rubygem-ms_rest_azure

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
