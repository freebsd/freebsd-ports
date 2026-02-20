PORTNAME=	devise-two-factor
PORTVERSION=	5.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise
WWW=		https://github.com/tinfoil/devise-two-factor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=7.0<8:devel/rubygem-activesupport-gitlab \
		rubygem-devise-rails-gitlab>=4.0<5:devel/rubygem-devise-rails-gitlab \
		rubygem-railties-gitlab>=7.0<8:www/rubygem-railties-gitlab \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
