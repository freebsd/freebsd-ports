# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unicorn
PORTVERSION=	5.5.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTTP server for Rack applications

LICENSE=	GPLv2 GPLv3 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-kgio>=2.6<3:devel/rubygem-kgio \
		rubygem-raindrops>=0.7<1:www/rubygem-raindrops

CONFLICTS_INSTALL=	rubygem-unicorn51

USES=		gem shebangfix
USE_RUBY=	yes

PLIST_FILES=	bin/unicorn bin/unicorn_rails

SHEBANG_FILES=	bin/unicorn* test/aggregate.rb test/benchmark/uconnect.perl
ruby_OLD_CMD=	.*ruby

.include <bsd.port.mk>
