# New ports collection makefile for:	Ruby/Amazon
# Date created:		9 February 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	amazon
PORTVERSION=	0.8.2
CATEGORIES=	www ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to Amazon's Web Services

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		NEWS README TODO
EXAMPLES=	example/*

RUBY_REQUIRE=	Ruby > 180

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		only works with Ruby 1.8.0 or later
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
