# New ports collection makefile for:	Ruby/TCPSocketPipe
# Date created:		20 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tcpsocketpipe
PORTVERSION=	1.8.2
CATEGORIES=	net ruby
MASTER_SITES=	http://rrr.jin.gr.jp/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	socketproxy.rb
EXTRACT_SUFX=	# none
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to create I/O pipes for TCP socket tunneling

USE_RUBY=	yes
USE_RUBY_FEATURES=	devel-logger

NO_BUILD=	yes
PLIST_FILES=	%%RUBY_SITELIBDIR%%/socketproxy.rb

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/socketproxy.rb ${RUBY_SITELIBDIR}/

.include <bsd.port.mk>
