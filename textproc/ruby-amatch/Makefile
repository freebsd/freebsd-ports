# New ports collection makefile for:	Ruby/amatch
# Date created:		10 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	amatch
PORTVERSION=	0.1.1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.ping.de/~flori/programs/ruby/amatch/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install

DOCS=		CHANGES README.en amatch.txt.en

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
