# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	devise-two-factor
PORTVERSION=	3.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport5>=0:devel/rubygem-activesupport5 \
		rubygem-attr_encrypted>=1.3:security/rubygem-attr_encrypted \
		rubygem-devise-rails5>0:devel/rubygem-devise-rails5 \
		rubygem-railties5>=0:www/rubygem-railties5 \
		rubygem-rotp>=2.0:devel/rubygem-rotp

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
