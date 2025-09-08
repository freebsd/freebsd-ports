PORTNAME=	railties
PORTVERSION=	7.1.5.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rails internals: application bootup, plugins, generators, and rake tasks
WWW=		https://github.com/rails/rails/tree/master/railties \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack71>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack71 \
		rubygem-activesupport71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport71 \
		rubygem-irb>=0:devel/rubygem-irb \
		rubygem-rackup>=1.0.0:www/rubygem-rackup \
		rubygem-rake>=12.2:devel/rubygem-rake \
		rubygem-thor>=1.2.2<2:devel/rubygem-thor \
		rubygem-zeitwerk>=2.6<3:devel/rubygem-zeitwerk

USES=		gem shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/rails

CONFLICTS_INSTALL=	rubygem-railties[0-9] rubygem-railties[0-9][0-9]

PORTSCOUT=	limit:^7\.1\.

SHEBANG_FILES=	lib/rails/generators/rails/app/templates/docker-entrypoint.tt

.include <bsd.port.mk>
