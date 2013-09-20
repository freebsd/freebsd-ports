# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	nora
PORTVERSION=	0.0.20041114
CATEGORIES=	www ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A rich set of Ruby libraries for Web applications

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

NO_STAGE=	yes
post-patch:
	@${RUBY} -i -pe 'sub(/malloc\.h/, "stdlib.h")' ${WRKSRC}/ext/web/escape_ext/escape_ext.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/ ${RUBY_MODEXAMPLESDIR}/
	@${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
