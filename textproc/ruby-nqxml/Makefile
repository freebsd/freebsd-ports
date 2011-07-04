# New ports collection makefile for:	NQXML
# Date created:		10 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	nqxml
PORTVERSION=	1.1.3p1
CATEGORIES=	textproc ruby
MASTER_SITES=	SF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A pure Ruby implementasion of a non-validating XML processor

DEPRECATED=	Doesn't work with Ruby 1.9
EXPIRATION_DATE=	2011-08-03

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		ChangeLog README Credits TODO

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/dispatcher
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${RUBY_MODEXAMPLESDIR}/dispatcher/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
