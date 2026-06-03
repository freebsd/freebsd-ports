PORTNAME=	rdtool
PORTVERSION=	0.6.39
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RD to HTML/man/etc. converter (RD is to Ruby as POD is to Perl)
WWW=		https://github.com/uwabami/rdtool

LICENSE=	GPLv2+ RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.txt
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-nkf>=0.1<1.0:net/rubygem-nkf

NO_ARCH=	yes

USES=		gem shebangfix
SHEBANG_FILES=	bin/rd2 bin/rdswap.rb
ruby_OLD_CMD=	/usr/bin/ruby1.9.1

PLIST_FILES=	bin/rd2 bin/rdswap.rb

.include <bsd.port.mk>
