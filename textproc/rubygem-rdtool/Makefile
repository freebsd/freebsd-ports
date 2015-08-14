# $FreeBSD$

PORTNAME=	rdtool
PORTVERSION=	0.6.38
PORTREVISION=	2
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RD to HTML/man/etc. converter (RD is to Ruby as POD is to Perl)

LICENSE=	GPLv2 GPLv3 RUBY
LICENSE_COMB=	dual

NO_ARCH=	yes

USES=		shebangfix
SHEBANG_FILES=	bin/rd2 bin/rdswap.rb
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rd2 bin/rdswap.rb

.include <bsd.port.mk>
