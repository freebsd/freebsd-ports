PORTNAME=	vagrant_cloud
PORTVERSION=	3.1.3
CATEGORIES=	sysutils rubygems devel
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby library for the HashiCorp Vagrant Cloud API
WWW=		https://developer.hashicorp.com/vagrant/vagrant-cloud/api/v2 \
		https://github.com/hashicorp/vagrant_cloud

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-excon1-gitlab>=1.0<2:devel/rubygem-excon1-gitlab \
		rubygem-log4r>=1.1<2:sysutils/rubygem-log4r \
		rubygem-oauth2-gitlab>2.0<3:net/rubygem-oauth2-gitlab \
		rubygem-rexml>=3.3<4:textproc/rubygem-rexml

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
