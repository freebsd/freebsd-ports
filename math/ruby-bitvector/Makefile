# New ports collection makefile for:	Ruby/BitVector
# Date created:		23 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bitvector
PORTVERSION=	0.1.6
CATEGORIES=	math ruby
MASTER_SITES=	http://www.ce.chalmers.se/~feldt/ruby/extensions/bitvector/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./-/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/bitvector
	${INSTALL_DATA} ${WRKSRC}/tests/* ${RUBY_EXAMPLESDIR}/bitvector/
	${MKDIR} ${RUBY_DOCDIR}/bitvector
.for f in NOTWRAPPED README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/bitvector/
.endfor
.endif

.include <bsd.port.mk>
