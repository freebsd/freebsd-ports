# New ports collection makefile for:	Ruby/GSL
# Date created:		22 December 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	0.3.9
CATEGORIES=	math ruby
MASTER_SITES=	http://www5d.biglobe.ne.jp/~ytsune/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rb-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension library for GSL (GNU Scientific Library)

LIB_DEPENDS=	gsl.5:${.CURDIR}/../gsl

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${WRKDIR}/rb-${PORTNAME}
CONFIGURE_ARGS=	-- --with-opt-dir="${LOCALBASE}"

EXAMPLES_EN=	samples/*
DOCS=		AUTHORS THANKS html rd

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
