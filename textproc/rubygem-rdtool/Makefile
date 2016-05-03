# $FreeBSD$

PORTNAME=	rdtool
PORTVERSION=	0.6.38
PORTREVISION=	3
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RD to HTML/man/etc. converter (RD is to Ruby as POD is to Perl)

LICENSE=	GPLv2 GPLv3 RUBY
LICENSE_COMB=	dual

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	bin/rd2 bin/rdswap.rb
ruby_OLD_CMD=	/usr/bin/ruby1.9.1

PLIST_FILES=	bin/rd2 bin/rdswap.rb

.include <bsd.port.mk>
