PORTNAME=	devise_pam_authenticatable2
PORTVERSION=	9.2.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Devise PAM authentication module using rpam2
WWW=		https://github.com/devkral/devise_pam_authenticatable2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-devise-rails61>=4.0.0:devel/rubygem-devise-rails61 \
		rubygem-rpam2>=4.0:security/rubygem-rpam2

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
