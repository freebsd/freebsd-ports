# New ports collection makefile for:	Ruby-html-parser
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	html-parser
PORTVERSION=	19990912.p1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.jin.gr.jp/~nahi/Ruby/html-parser/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

MODULES=	formatter.rb	html-parser.rb	sgml-parser.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/html-parser
	${INSTALL_DATA} ${WRKSRC}/README.html ${RUBY_DOCDIR}/html-parser/
.endif

.include <bsd.port.mk>
