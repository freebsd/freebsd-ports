# New ports collection makefile for:	ruby-rttool
# Date created:		2010-10-04
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rttool
PORTVERSION=	1.0.3
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubyist.net/~rubikitch/archive/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/ruby-rttool|}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	RT into HTML and plain text converter

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_RDTOOL=	yes

RUBY_SHEBANG_FILES=	bin/rt/* lib/rt/*
RUBY_MODNAME=	rt

DOCS_EN=	rttool.en.html rttool.en.rd
DOCS_JA=	rttool.ja.html rttool.ja.rd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${RUBY_MODEXAMPLESDIR}
.endif

.include <bsd.port.mk>
