# New ports collection makefile for:	Ruby/Devel::Logger
# Date created:		13 April 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	devel-logger
PORTVERSION=	1.1.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://rrr.jin.gr.jp/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A lightweight logging library for Ruby

USE_RUBY=	yes
NO_BUILD=	yes

EXAMPLES=	sample/*
DOCS=		README

do-install:
	cd ${WRKSRC}; ${RUBY} ./install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
