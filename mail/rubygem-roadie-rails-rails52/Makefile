PORTNAME=	roadie-rails
PORTVERSION=	2.2.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Helper for generating HTML mails in Rails applications
WWW=		https://github.com/Mange/roadie-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties52>=3.0:www/rubygem-railties52 \
		rubygem-roadie3>=3.1:mail/rubygem-roadie3

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	setup.sh

.include <bsd.port.mk>
