PORTNAME=	devise-two-factor
PORTVERSION=	6.3.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise
WWW=		https://github.com/tinfoil/devise-two-factor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport72>=7.0<8.2:devel/rubygem-activesupport72 \
		rubygem-devise-rails72>=4.0<6.0:devel/rubygem-devise-rails72 \
		rubygem-railties72>=7.0<8.2:www/rubygem-railties72 \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
