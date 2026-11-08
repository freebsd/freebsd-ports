PORTNAME=	winrm-elevated
PORTVERSION=	1.2.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for running commands as elevated
WWW=		https://github.com/WinRb/winrm-elevated

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-winrm>=2.0<3:sysutils/rubygem-winrm \
		rubygem-winrm-fs>=1.0<2:filesystems/rubygem-winrm-fs

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
