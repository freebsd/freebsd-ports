# New ports collection makefile for:	RubyNumruMisc
# Date created:		14 March 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	numru_misc
PORTVERSION=	0.0.5
CATEGORIES=	math ruby
MASTER_SITES=	ftp://www.gfd-dennou.org/arch/ruby/products/numru-misc/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	numru-misc-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	murakami@ahs.scitec.kobe-u.ac.jp
COMMENT=	Collection of misc functions and classes to facilitate programming

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray \
		${RUBY_SITELIBDIR}/narray_miss.rb:${PORTSDIR}/math/ruby-narray_miss

USE_RUBY=	yes
NO_BUILD=	yes

DOCS=		ChangeLog doc/*

do-install:
	@cd ${WRKSRC}/ && ${RUBY} ./install.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
