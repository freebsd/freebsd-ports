PORTNAME=	winrm-elevated
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for running commands as elevated
WWW=		https://github.com/WinRb/winrm-elevated

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-erubi>=1.8<2:www/rubygem-erubi \
		rubygem-winrm-gitlab>=2.0<3:sysutils/rubygem-winrm-gitlab \
		rubygem-winrm-fs-gitlab>=1.0<2:filesystems/rubygem-winrm-fs-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
