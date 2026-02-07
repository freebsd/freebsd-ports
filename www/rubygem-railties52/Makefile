PORTNAME=	railties
PORTVERSION=	5.2.8.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rails internals bootup, plugins, generators, and rake tasks
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/railties

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack52>=${PORTVERSION}:www/rubygem-actionpack52 \
		rubygem-activesupport52>=${PORTVERSION}:devel/rubygem-activesupport52 \
		rubygem-method_source>=0:devel/rubygem-method_source \
		rubygem-rake>=0.8.7:devel/rubygem-rake \
		rubygem-thor>=0.19.0<2.0:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rails

CONFLICTS_INSTALL=	rubygem-railties[0-9] rubygem-railties[0-9][0-9]

PORTSCOUT=	limit:^5\.2\.

.include <bsd.port.mk>
