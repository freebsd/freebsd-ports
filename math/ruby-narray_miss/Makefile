# New ports collection makefile for:	Ruby/NArrayMiss
# Date created:		15 Febrary 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	narray_miss
PORTVERSION=	1.1.1
CATEGORIES=	math ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/narray_miss/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	murakami@ahs.scitec.kobe-u.ac.jp
COMMENT=	Additional class with processing of missing value to NArray

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		ChangeLog README doc/narray_miss.html

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.endif

.include <bsd.port.mk>
