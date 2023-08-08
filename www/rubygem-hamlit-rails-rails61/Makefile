PORTNAME=	hamlit-rails
PORTVERSION=	0.2.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Hamlit (haml) generators for Rails 61
WWW=		https://github.com/mfung/hamlit-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport61>=0:devel/rubygem-activesupport61 \
		rubygem-actionpack61>=0:www/rubygem-actionpack61 \
		rubygem-hamlit>=1.2.0:www/rubygem-hamlit \
		rubygem-railties61>=0:www/rubygem-railties61

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	bin/setup
bash_CMD=	${SH}

.include <bsd.port.mk>
