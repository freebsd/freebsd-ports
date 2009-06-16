# New ports collection makefile for:	ruby-spread
# Date created:		2002 July 22
# Whom:			seanc@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	spread
PORTVERSION=	1.0
CATEGORIES=	net ruby
MASTER_SITES=	http://www.omniti.com/~george/rb_spread/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rb_${PORTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the Spread library

LIB_DEPENDS=	tspread.1:${PORTSDIR}/net/spread

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}

INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/flooder.rb ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/user.rb ${RUBY_MODEXAMPLESDIR}
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}
.endif

.include <bsd.port.mk>
