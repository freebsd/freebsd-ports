# New ports collection makefile for:	Ruby-NArray
# Date created:		1 Feb 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	narray
PORTVERSION=	0.5.7p2
CATEGORIES=	math ruby
MASTER_SITES=	http://www.ir.isas.ac.jp/~masa/ruby/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Numerical N-dimensional array library for Ruby

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOC_EN=		ChangeLog	README.en	SPEC.en
DOC_JA=		README.ja	SPEC.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOC_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOC_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/speed/*.rb ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
