# New ports collection makefile for:	Ruby-Tempura
# Date created:		18 March 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tempura
PORTVERSION=	0.1.2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.imasy.or.jp/~hisa/ruby/tempura/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	TEMPlate Utility for Ruby Application

USE_RUBY=	yes
RUBY_FEATURES=	rexml

NO_BUILD=	yes

DOCS_EN=	ChangeLog README
DOCS_JA=	README.ja doc

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
