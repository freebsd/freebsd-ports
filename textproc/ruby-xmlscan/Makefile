# New ports collection makefile for:	ruby-xmlscan
# Date created:		7 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xmlscan
PORTVERSION=	0.2.3
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	High-performance non-validating XML parser written in 100% pure Ruby

NO_LATEST_LINK=	yes
USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	ChangeLog \
		README \
		THANKS \
		doc/changes.* \
		doc/en/*
DOCS_JA=	doc/ja/*

do-install:
	${CP} -R ${WRKSRC}/lib/xmlscan ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
