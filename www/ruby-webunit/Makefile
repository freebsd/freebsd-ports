# New ports collection makefile for:	Ruby/WebUnit
# Date created:		20 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	webunit
PORTVERSION=	20040429
CATEGORIES=	www textproc ruby
MASTER_SITES=	http://www.xpenguin.biz/download/webunit/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}++
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby API for automated unit testing of web sites

RUN_DEPENDS=	${RUBY_SITELIBDIR}/html-parser.rb:${PORTSDIR}/textproc/ruby-html-parser \
		${RUBY_SITELIBDIR}/htmlrepair.rb:${PORTSDIR}/textproc/ruby-htmlrepair \
		${RUBY_SITELIBDIR}/htmlsplit.rb:${PORTSDIR}/textproc/ruby-htmlsplit

USE_RUBY=	yes
USE_RUBY_FEATURES=	rexml testunit

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

EXAMPLES=	sample/*
DOCS=		*.html *.rd

do-install:
	${CP} -R ${WRKSRC}/lib/webunit* ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MV} ${RUBY_MODDOCDIR}/*-ja.* ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
