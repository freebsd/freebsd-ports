PORTNAME=	devise-two-factor
PORTVERSION=	4.1.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41-rails70

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise
WWW=		https://github.com/tinfoil/devise-two-factor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=7.0<8:devel/rubygem-activesupport70 \
		rubygem-attr_encrypted3>=1.3<5:security/rubygem-attr_encrypted3 \
		rubygem-devise-rails70>=4.0<5:devel/rubygem-devise-rails70 \
		rubygem-railties70>=7.0<7.1:www/rubygem-railties70 \
		rubygem-rotp>=6.0<7:devel/rubygem-rotp

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.0\.

.include <bsd.port.mk>
