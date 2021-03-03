# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	railties
PORTVERSION=	6.1.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=${PORTVERSION}:www/rubygem-actionpack61 \
		rubygem-activesupport61>=${PORTVERSION}:devel/rubygem-activesupport61 \
		rubygem-method_source>=0:devel/rubygem-method_source \
		rubygem-rake>=0.8.7:devel/rubygem-rake \
		rubygem-thor>=1.0<2:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rails

CONFLICTS_INSTALL=	rubygem-railties4 rubygem-railties5 rubygem-railties50 rubygem-railties52 rubygem-railties60

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
