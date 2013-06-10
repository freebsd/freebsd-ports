# $FreeBSD$

PORTNAME=	rdtool
PORTVERSION=	0.6.38
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RD to HTML/man/etc. converter (RD is to Ruby as POD is to Perl)

RUN_DEPENDS=	rubygem-racc>=1.4.6:${PORTSDIR}/devel/rubygem-racc

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USE_RAKE=	yes
PLIST_FILES=	bin/rd2 bin/rdswap.rb

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
