PORTNAME=	devise-two-factor
PORTVERSION=	5.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=7.0<8:devel/rubygem-activesupport70 \
		rubygem-devise-rails70>=4.0<5:devel/rubygem-devise-rails70 \
		rubygem-railties70>=7.0<8:www/rubygem-railties70 \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
