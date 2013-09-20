# Created by: Shinsuke Matsui (<smatsui@karashi.org>)
# $FreeBSD$

PORTNAME=	erbscan
PORTVERSION=	0.0.20030723b
CATEGORIES=	textproc ruby
MASTER_SITES=	http://raa.ruby-lang.org/cache/erbscan/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	smatsui@karashi.org
COMMENT=	ERB compiler accelerator

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif

post-patch:
	@${RUBY} -i -pe 'sub(/malloc\.h/, "stdlib.h")' ${WRKSRC}/erbscan.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>
