# New ports collection makefile for:	Ruby-html-parser
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	html-parser
PORTVERSION=	19990912p2
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.jin.gr.jp/~nahi/Ruby/html-parser/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	HTML-parser package for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

MODULES=	formatter.rb	html-parser.rb	sgml-parser.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
