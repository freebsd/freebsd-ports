# New ports collection makefile for:	ICMPModule for Ruby
# Date created:		1 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	icmp
PORTVERSION=	0.1.1
CATEGORIES=	net ruby
MASTER_SITES=	http://www.notwork.org/~gotoyuzo/ruby/src/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

EXAMPLES=	ping.rb

post-install:
	${INSTALL_DATA} ${WRKSRC}/icmp.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/icmp
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/icmp/
.endfor
.endif

.include <bsd.port.mk>
