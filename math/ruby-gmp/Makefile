# New ports collection makefile for:	libgmp-ruby
# Date created:		23 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gmp
PORTVERSION=	1.0
CATEGORIES=	math ruby
MASTER_SITES=	http://synapsa.infoland.int.pl/~taw/libgmp-ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	lib${PORTNAME}-ruby_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby bindings to GNU Multiprecision Library

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
INSTALL_TARGET=	site-install

DOCS=		ChangeLog README doc/PRECISION doc/TODO

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 (needs to link against shared library)"
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
