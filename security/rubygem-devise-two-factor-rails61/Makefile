PORTNAME=	devise-two-factor
PORTVERSION=	4.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport61>=0<7.1:devel/rubygem-activesupport61 \
		rubygem-attr_encrypted>=3<4:security/rubygem-attr_encrypted \
		rubygem-devise-rails61>=4.0<5:devel/rubygem-devise-rails61 \
		rubygem-railties61>=0<7.1:www/rubygem-railties61 \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
