# $FreeBSD$

PORTNAME=	unicorn
PORTVERSION=	5.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	51

MAINTAINER=	idefix@fechner.net
COMMENT=	Unicorn is an HTTP server for Rack applications

LICENSE=	GPLv2 GPLv3 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-kgio>=2.6:devel/rubygem-kgio \
		rubygem-raindrops>=0.7:www/rubygem-raindrops

USES=		gem shebangfix
USE_RUBY=	yes

CONFLICTS_INSTALL=	rubygem-unicorn
PORTSCOUT=	limit:^5\.1

PLIST_FILES=	bin/unicorn bin/unicorn_rails

SHEBANG_FILES=	bin/unicorn* test/aggregate.rb
ruby_OLD_CMD=	.*ruby

.include <bsd.port.mk>
