PORTNAME=	vagrant_cloud
PORTVERSION=	3.1.2
CATEGORIES=	sysutils rubygems devel
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vagrant Cloud API wrapper for Ruby
WWW=		https://www.vagrantup.com/docs/cli/cloud.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-excon>=1.0:devel/rubygem-excon \
		rubygem-oauth2>2.0:net/rubygem-oauth2 \
		rubygem-log4r>=1.1<1.2:sysutils/rubygem-log4r \
		rubygem-rexml>=3.3:textproc/rubygem-rexml

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
