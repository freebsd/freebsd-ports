# New ports collection makefile for:	ruby-aws
# Date created:		2008-03-30
# Whom:			IWATSUKI Hiroyuki <don@na.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	aws
PORTVERSION=	0.8.1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	don@na.rim.or.jp
COMMENT=	A Ruby interface to Amazon Web Services

CONFLICTS=	ruby-amazon-[0-9]*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		COPYING INSTALL NEWS README
EXAMPLES=	example/*

RUBY_REQUIRE=	Ruby > 180

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		depends on Ruby 1.8.0 or later
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
