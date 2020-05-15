# $FreeBSD$

PORTNAME=	winrm-elevated
PORTVERSION=	1.2.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for running commands as elevated

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-erubi>=1.8<2:www/rubygem-erubi \
		rubygem-winrm>=2.0<3:sysutils/rubygem-winrm \
		rubygem-winrm-fs>=1.0<2:sysutils/rubygem-winrm-fs

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
