# New ports collection makefile for:	Ruby/GSL
# Date created:		22 December 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	1.14.4
CATEGORIES=	math ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	rb-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rb-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Ruby extension library for GSL (GNU Scientific Library)

LIB_DEPENDS=	gsl.15:${PORTSDIR}/math/gsl

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

CONFIGURE_ARGS=	-- --with-opt-dir="${LOCALBASE}"

EXAMPLES_EN=	examples/*
DOCS=		AUTHORS ChangeLog THANKS html rd

post-extract:
	${FIND} ${WRKSRC} '(' -name '.DS_Store' -o -name '*~' ')' -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
