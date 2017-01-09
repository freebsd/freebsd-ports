# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	5.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack5>=${PORTVERSION}:www/rubygem-actionpack5 \
		rubygem-activesupport5>=${PORTVERSION}:devel/rubygem-activesupport5 \
		rubygem-method_source>=0:devel/rubygem-method_source \
		rubygem-rake>=0.8.7:devel/rubygem-rake \
		rubygem-thor>=0.18.1:devel/rubygem-thor

CONFLICTS_INSTALL=	rubygem-railties-[0-9]* rubygem-railties41-[0-9]*

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rails

.include <bsd.port.mk>
