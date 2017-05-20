# $FreeBSD$

PORTNAME=	vagrant-vbguest
PORTVERSION=	0.14.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Vagrant plugin to install the VirtualBoxAdditions into the guest VM

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-i18n>=0:devel/rubygem-i18n \
		rubygem-log4r>=0:sysutils/rubygem-log4r \
		rubygem-micromachine>=2.0.0:devel/rubygem-micromachine

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
