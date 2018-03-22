# $FreeBSD$

PORTNAME=	devise_pam_authenticatable2
PORTVERSION=	9.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Devise PAM authentication module using rpam2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-devise-rails5>=4.0.0:devel/rubygem-devise-rails5 \
		rubygem-rpam2-3>=3.0:security/rubygem-rpam2-3

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
