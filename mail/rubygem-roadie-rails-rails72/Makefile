PORTNAME=	roadie-rails
PORTVERSION=	3.4.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper for generating HTML mails in Rails applications
WWW=		https://github.com/Mange/roadie-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties72>=5.1<8.2:www/rubygem-railties72 \
		rubygem-roadie>=5.0<6:mail/rubygem-roadie

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	setup.sh

.include <bsd.port.mk>
