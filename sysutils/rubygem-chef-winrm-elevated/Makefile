PORTNAME=	chef-winrm-elevated
PORTVERSION=	1.2.5
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library for running commands via WinRM as elevated through a scheduled task
WWW=		https://github.com/chef/chef-winrm-elevated

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-winrm>=2.3.11:sysutils/rubygem-chef-winrm \
		rubygem-chef-winrm-fs>=1.3.7:filesystems/rubygem-chef-winrm-fs \
		rubygem-erubi>=1.8:www/rubygem-erubi

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
