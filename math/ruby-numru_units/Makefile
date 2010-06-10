# New ports collection makefile for:	RubyNumruUnits
# Date created:		14 March 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	numru_units
PORTVERSION=	1.6
CATEGORIES=	math ruby
MASTER_SITES=	ftp://www.gfd-dennou.org/arch/ruby/products/numru-units/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	numru-units-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	A class to handle units of physical quantities for Ruby

USE_RUBY=	yes
NO_BUILD=	yes

DOCS=		ChangeLog doc/units.html doc/units.rd

do-install:
	@cd ${WRKSRC}/ && ${RUBY} ./install.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.endif

.include <bsd.port.mk>
