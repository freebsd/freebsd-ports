# New ports collection makefile for:	Ruby/Algebra
# Date created:		8 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	algebra
PORTVERSION=	0.57
CATEGORIES=	math ruby
MASTER_SITES=	http://blade.nagaokaut.ac.jp/~sinara/ruby/math/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library for mathematical (algebraic) computations

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	doc/*.txt	doc/*.rd	doc/*.html
DOCS_JA=	doc-ja/*.txt	doc-ja/*.rd	doc-ja/*.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
