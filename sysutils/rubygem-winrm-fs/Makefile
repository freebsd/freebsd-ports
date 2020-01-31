# $FreeBSD$

PORTNAME=	winrm-fs
PORTVERSION=	1.3.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for file system operations via WinRM

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-erubi>=1.8<2:www/rubygem-erubi \
		rubygem-logging>=1.6.1<3.0:devel/rubygem-logging \
		rubygem-rubyzip>=2.0<3:archivers/rubygem-rubyzip \
		rubygem-winrm>=2.0<3:sysutils/rubygem-winrm

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rwinrmcp

.include <bsd.port.mk>
