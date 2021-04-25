# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>

PORTNAME=	devise-two-factor
PORTVERSION=	4.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport5>=0<6.2:devel/rubygem-activesupport5 \
		rubygem-attr_encrypted>=1.3<4:security/rubygem-attr_encrypted \
		rubygem-devise-rails5>=4.0<5:devel/rubygem-devise-rails5 \
		rubygem-railties5>=0<6.2:www/rubygem-railties5 \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
