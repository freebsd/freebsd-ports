# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	propshaft
PORTVERSION=	0.5.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Deliver assets for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

BROKEN_RUBY26=	yes

RUN_DEPENDS=	rubygem-actionpack70>=7.0.0:www/rubygem-actionpack70 \
		rubygem-activesupport70>=7.0.0:devel/rubygem-activesupport70 \
		rubygem-rack>=0,3:www/rubygem-rack \
		rubygem-railties70>=7.0.0:www/rubygem-railties70

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
