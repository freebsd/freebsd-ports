# New ports collection makefile for:	erbscan
# Date created:		17 November 2006
# Whom:				Shinsuke Matsui (<smatsui@karashi.org>)
#
# $FreeBSD$
#

PORTNAME=	erbscan
PORTVERSION=	0.0.20030723b
CATEGORIES=	textproc ruby
MASTER_SITES=	http://raa.ruby-lang.org/cache/erbscan/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	smatsui@karashi.org
COMMENT=	ERB compiler accelerator

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

RUBY_REQUIRE=	Ruby > 180

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		only works with Ruby 1.8.0 or later
.endif

post-patch:
	@${RUBY} -i -pe 'sub(/malloc\.h/, "stdlib.h")' ${WRKSRC}/erbscan.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>
