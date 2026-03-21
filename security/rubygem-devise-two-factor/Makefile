PORTNAME=	devise-two-factor
PORTVERSION=	6.4.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise
WWW=		https://github.com/tinfoil/devise-two-factor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport81>=7.0<8.2:devel/rubygem-activesupport81 \
		rubygem-devise-rails81>=4.0<6.0:devel/rubygem-devise-rails81 \
		rubygem-railties81>=7.0<8.2:www/rubygem-railties81 \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
