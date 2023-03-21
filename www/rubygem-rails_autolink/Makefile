PORTNAME=	rails_autolink
PORTVERSION=	1.1.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Extraction of the auto_link method from rails, removed in 3.1
WWW=		https://github.com/tenderlove/rails_autolink

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionview61>=3.1:devel/rubygem-actionview61 \
		rubygem-activesupport61>=3.1:devel/rubygem-activesupport61 \
		rubygem-railties61>=3.1:www/rubygem-railties61

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
