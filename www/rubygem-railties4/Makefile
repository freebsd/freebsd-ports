# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	4.2.10
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack4>=${PORTVERSION}:www/rubygem-actionpack4 \
		rubygem-activesupport4>=${PORTVERSION}:devel/rubygem-activesupport4 \
		rubygem-rake>=0.8.7:devel/rubygem-rake \
		rubygem-thor>=0.18.1:devel/rubygem-thor

CONFLICTS_INSTALL=	rubygem-railties rubygem-railties41 rubygem-railties5

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rails

.include <bsd.port.mk>
