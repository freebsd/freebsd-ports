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
USE_RUBY_RDTOOL=	yes

do-build:
.if !defined(NOPORTDOCS)
.for f in acl.rd acl.rd.ja
	@cd ${WRKSRC}/doc; \
	${RUBY_RD2} ${f} > ${f:S/.rd/.html/}
.endfor
.endif

do-install:
	@cd ${WRKSRC}; \
	${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/acltest.rb ${RUBY_MODEXAMPLESDIR}
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in README doc/acl.rd doc/acl.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.for f in README.ja doc/acl.rd.ja doc/acl.html.ja
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja
.endfor
.endif

.include <bsd.port.mk>
