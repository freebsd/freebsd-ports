# New ports collection makefile for:	Ruby/amrita
# Date created:		10 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	amrita
PORTVERSION=	0.9.6
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.brain-tokyo.jp/research/amrita/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_FEATURES=	strscan

RUBY_SHEBANG_FILES=	${BINS}

BINS=		${WRKSRC}/bin/*
DOCS=		ChangeLog README* docs/*

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
	${INSTALL_SCRIPT} ${BINS} ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
