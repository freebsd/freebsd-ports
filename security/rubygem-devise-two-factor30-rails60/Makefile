# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	devise-two-factor
# 3.0.3 does not work with newer rails version, so downgrade here
PORTVERSION=	3.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	30-rails60

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=0:devel/rubygem-activesupport60 \
		rubygem-attr_encrypted>=1.3<4:security/rubygem-attr_encrypted \
		rubygem-devise-rails60>=4.0<5:devel/rubygem-devise-rails60 \
		rubygem-railties60>=0:www/rubygem-railties60 \
		rubygem-rotp>=2.0:devel/rubygem-rotp

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.0\.0

.include <bsd.port.mk>
