# New ports collection makefile for:	Ruby/GSL
# Date created:		22 December 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	0.2.3
CATEGORIES=	math ruby
MASTER_SITES=	http://www5d.biglobe.ne.jp/~ytsune/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rb-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	gsl.3:${.CURDIR}/../gsl

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

WRKSRC=		${WRKDIR}/rb-${PORTNAME}
CONFIGURE_ARGS=	-- --with-opt-dir="${LOCALBASE}"

EXAMPLES_EN=	test/*
DOCS_EN=	AUTHORS ChangeLog README.html README.rd doc/*
DOCS_JA=	README.ja.html README.ja.rd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
