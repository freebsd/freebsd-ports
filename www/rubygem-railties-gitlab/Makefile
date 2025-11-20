PORTNAME=	railties
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Rails internals: application bootup, plugins, generators, and rake tasks
WWW=		https://github.com/rails/rails/tree/master/railties \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack-gitlab \
		rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-cgi>=0:www/rubygem-cgi \
		rubygem-irb-gitlab>=0:devel/rubygem-irb-gitlab \
		rubygem-rackup10>=1.0.0:www/rubygem-rackup10 \
		rubygem-rake>=12.2:devel/rubygem-rake \
		rubygem-thor>=1.2.2<2:devel/rubygem-thor \
		rubygem-tsort>=0.2:devel/rubygem-tsort \
		rubygem-zeitwerk>=2.6<3:devel/rubygem-zeitwerk

USES=		gem shebangfix

SHEBANG_FILES=	lib/rails/generators/rails/app/templates/docker-entrypoint.tt

CONFLICTS_INSTALL=	rubygem-railties[0-9] rubygem-railties[0-9][0-9]

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

PLIST_FILES=	bin/rails

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
