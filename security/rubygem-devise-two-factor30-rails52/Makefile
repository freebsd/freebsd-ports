# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	devise-two-factor
PORTVERSION=	3.0.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	30-rails52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Barebones two-factor authentication with Devise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport52>=0<5.3:devel/rubygem-activesupport52 \
		rubygem-attr_encrypted>=1.3<4:security/rubygem-attr_encrypted \
		rubygem-devise-rails52>=4.0<5:devel/rubygem-devise-rails52 \
		rubygem-railties52>=0<5.3:www/rubygem-railties52 \
		rubygem-rotp>=2.0:devel/rubygem-rotp

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.0\.

.include <bsd.port.mk>
