# New ports collection makefile for:	Ruby/Math3d
# Date created:		8 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	math3d
PORTVERSION=	0.04
CATEGORIES=	math ruby
MASTER_SITES=	http://www2.giganet.net/~yoshi/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library for mathematics for 3D graphics

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

BROKEN=		"Does not compile"

pre-patch:
	cd ${WRKSRC}; ${RUBY} -i -pe 'sub(/\r/, "")' *.[ch]

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/manual.en ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/manual.jis ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
