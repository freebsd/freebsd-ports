PORTNAME=	railties
PORTVERSION=	7.0.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rails internals: application bootup, plugins, generators, and rake tasks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=${PORTVERSION}:www/rubygem-actionpack70 \
		rubygem-activesupport70>=${PORTVERSION}:devel/rubygem-activesupport70 \
		rubygem-method_source>=0:devel/rubygem-method_source \
		rubygem-rake>=12.2:devel/rubygem-rake \
		rubygem-thor>=1.0<2:devel/rubygem-thor \
		rubygem-zeitwerk>=2.5<3:devel/rubygem-zeitwerk

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rails

CONFLICTS_INSTALL=	rubygem-railties4 rubygem-railties5 rubygem-railties50 rubygem-railties52 rubygem-railties60 rubygem-railties61

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
