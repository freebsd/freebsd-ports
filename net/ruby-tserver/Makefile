# New ports collection makefile for:	Ruby/TServer
# Date created:		13 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tserver
PORTVERSION=	0.2.1
CATEGORIES=	net ruby
MASTER_SITES=	http://www.tmtm.org/ruby/tserver/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library for writing a preforking server like Apache

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/sample/*

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/tserver.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.html ${RUBY_MODDOCDIR}/ja/
	${INSTALL_DATA} ${WRKSRC}/tommy.css ${RUBY_MODDOCDIR}/ja/
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
