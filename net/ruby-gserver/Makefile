# New ports collection makefile for:	GServer.rb
# Date created:		12 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gserver
PORTVERSION=	1.1
CATEGORIES=	net ruby
MASTER_SITES=	http://www.rogare.com/downloads/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	GServer
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_ZIP=	yes
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/GServer.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/HttpEchoServer.rb ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
