# New ports collection makefile for:	ruby-radius
# Date created:		11 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	radius
PORTVERSION=	1.0.0
CATEGORIES=	net ruby
MASTER_SITES=	http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby module that provides an interface to the RADIUS protocol

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/examples/*

NO_BUILD=	yes

DOCS=		README doc/*

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
