# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	acl
PORTVERSION=	1.0.1
CATEGORIES=	security ipv6 ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ufo@februality.com
COMMENT=	Ruby module to provide Access Control List checks

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	doc/acl.rd doc/ja/acl.rd.ja

NO_STAGE=	yes
post-extract:
	${MKDIR} ${WRKSRC}/doc/ja
	${MV} ${WRKSRC}/README ${WRKSRC}/doc/
	${MV} ${WRKSRC}/README.ja ${WRKSRC}/doc/*.ja ${WRKSRC}/doc/ja/

do-install:
	@cd ${WRKSRC}; ${RUBY} install.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/acltest.rb ${RUBY_MODEXAMPLESDIR}
	${MKDIR} ${RUBY_MODDOCDIR}
	${CP} -R ${WRKSRC}/doc/* ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
