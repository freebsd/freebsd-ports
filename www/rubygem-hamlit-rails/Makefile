PORTNAME=	hamlit-rails
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hamlit (haml) generators for Rails 4+
WWW=		https://github.com/mfung/hamlit-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport71>=4.0.1:devel/rubygem-activesupport71 \
		rubygem-actionpack71>=4.0.1:www/rubygem-actionpack71 \
		rubygem-hamlit>=1.2.0:www/rubygem-hamlit \
		rubygem-railties71>=4.0.1:www/rubygem-railties71

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/setup
bash_CMD=	${SH}

.include <bsd.port.mk>
