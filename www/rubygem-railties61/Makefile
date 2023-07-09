PORTNAME=	railties
PORTVERSION=	6.1.7.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks
WWW=		https://github.com/rails/rails/tree/master/railties \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack61 \
		rubygem-activesupport61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport61 \
		rubygem-method_source>=0:devel/rubygem-method_source \
		rubygem-rake>=12.2:devel/rubygem-rake \
		rubygem-thor>=1.0<2:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rails

CONFLICTS_INSTALL=	rubygem-railties4 rubygem-railties5 rubygem-railties50 rubygem-railties52 rubygem-railties60

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
