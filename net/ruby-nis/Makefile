# New ports collection makefile for:	ruby-nis
# Date created:		21 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	nis
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	net ruby
MASTER_SITES=	SF/ruby-${PORTNAME}/ruby-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby library to use the NIS/YP API

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
INSTALL_TARGET=	site-install

DOCS_EN=	README README.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
