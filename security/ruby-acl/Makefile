# New ports collection makefile for:	Ruby-acl
# Date created:		7 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	acl
PORTVERSION=	1.0.1
CATEGORIES=	security ipv6 ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

do-build:
.if !defined(NOPORTDOCS)
.for f in acl.rd acl.rd.ja
	@cd ${WRKSRC}/doc; \
	${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor
.endif

do-install:
	@cd ${WRKSRC}; \
	${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/acl
	${INSTALL_DATA} ${WRKSRC}/acltest.rb ${RUBY_EXAMPLESDIR}/acl
	${MKDIR} ${RUBY_DOCDIR}/acl/ja
.for f in README doc/acl.rd doc/acl.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/acl
.endfor
.for f in README.ja doc/acl.rd.ja doc/acl.html.ja
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/acl/ja
.endfor
.endif

.include <bsd.port.mk>
