# $FreeBSD$

PORTNAME=	winrm-fs
PORTVERSION=	0.2.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for file system operations via WinRM

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-erubis>=2.7:www/rubygem-erubis \
		rubygem-logging>=1.6.1:devel/rubygem-logging \
		rubygem-rubyzip>=1.1:archivers/rubygem-rubyzip \
		rubygem-winrm>=1.3.0:sysutils/rubygem-winrm

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rwinrmcp

.include <bsd.port.mk>
