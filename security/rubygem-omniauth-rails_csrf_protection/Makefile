PORTNAME=	omniauth-rails_csrf_protection
PORTVERSION=	1.0.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Mitigation against CVE-2015-9284 for OmniAuth
WWW=		https://github.com/cookpad/omniauth-rails_csrf_protection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-actionpack61>=4.2:www/rubygem-actionpack61 \
		rubygem-omniauth>=2.0<3:security/rubygem-omniauth

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
