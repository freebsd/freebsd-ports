# New ports collection makefile for:	Ruby/TCPSocketPipe
# Date created:		20 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tcpsocketpipe
PORTVERSION=	1.8.1
CATEGORIES=	net ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	TCPSocketPipe-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to create I/O pipes for TCP socket tunneling

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dump.rb:${PORTSDIR}/converters/ruby-dump.rb

USE_RUBY=	yes
USE_RUBY_FEATURES=	devel-logger

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/TCPSocketPipe.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/monitor.rb ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
