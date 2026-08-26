PORTNAME=	roadie-rails
PORTVERSION=	3.4.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper for generating HTML mails in Rails applications
WWW=		https://github.com/Mange/roadie-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties81>=5.1<8.2:www/rubygem-railties81 \
		rubygem-roadie>=5.0<6:mail/rubygem-roadie

USES=		gem shebangfix

SHEBANG_FILES=	setup.sh

NO_ARCH=	yes

.include <bsd.port.mk>
