# New ports collection makefile for:	ruby-sha1
# Date created:		3 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sha1
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	security ruby
MASTER_SITES=	http://www.omcl.org/~spcoltri/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/sha1
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/sha1/
.endif

.include <bsd.port.mk>
