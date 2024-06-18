PORTNAME=	vagrant_cloud
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	sysutils rubygems devel
MASTER_SITES=	RG

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Vagrant Cloud API wrapper for Ruby
WWW=		https://www.vagrantup.com/docs/cli/cloud.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rubygem-rest-client>=2.0.2:www/rubygem-rest-client
RUN_DEPENDS=	rubygem-excon>=0.73<1.0:devel/rubygem-excon \
		rubygem-log4r>=1.1.10<1.2:sysutils/rubygem-log4r \
		rubygem-rexml32>=3.2.5:textproc/rubygem-rexml32

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
