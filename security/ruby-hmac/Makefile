# New ports collection makefile for:	ruby-hmac
# Date created:		20 February 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	hmac
PORTVERSION=	0.3
CATEGORIES=	security ruby
MASTER_SITES=	http://deisui.org/~ueno/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library which implements the HMAC algorithm

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/hmac*.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
