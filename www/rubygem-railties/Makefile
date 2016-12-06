# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	3.2.22.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack>=${PORTVERSION}:www/rubygem-actionpack \
		rubygem-activesupport>=${PORTVERSION}:devel/rubygem-activesupport \
		rubygem-rack-ssl>=1.3.2:www/rubygem-rack-ssl \
		rubygem-rake>=0.8.7:devel/rubygem-rake \
		rubygem-rdoc3>=3.4:devel/rubygem-rdoc3 \
		rubygem-thor>=0.14.6:devel/rubygem-thor

CONFLICTS_INSTALL=	rubygem-railties4-[0-9]* rubygem-railties41-[0-9]*

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rails

DEPRECATED=	Upstream support ended
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
