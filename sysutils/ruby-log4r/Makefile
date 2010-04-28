# New ports collection makefile for:	Log4r
# Date created:		13 January 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	log4r
PORTVERSION=	1.0.5
CATEGORIES=	sysutils ruby
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Log4r%20${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A flexible logging library written in Ruby

USE_RUBY=	yes

NO_BUILD=	yes

EXAMPLES=	examples/*
DOCS=		README changelog doc/*

do-install:
	cd ${WRKSRC}; ${RUBY} ./install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
