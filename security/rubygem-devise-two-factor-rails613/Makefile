# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>

PORTNAME=	devise-two-factor
PORTVERSION=	4.0.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport613>=0<6.2:devel/rubygem-activesupport613 \
		rubygem-attr_encrypted>=3<4:security/rubygem-attr_encrypted \
		rubygem-devise-rails613>=4.0<5:devel/rubygem-devise-rails613 \
		rubygem-railties613>=0<6.2:www/rubygem-railties613 \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
