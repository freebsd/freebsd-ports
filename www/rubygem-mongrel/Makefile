# Ports collection makefile for:	mongrel
# Date created:				20 May 2006
# Whom:					Rui Lopes (<rgl ruilopes com>)
#
# $FreeBSD$

PORTNAME=	mongrel
PORTVERSION=	1.1.5
PORTREVISION=	3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast HTTP 1.1 library and server for Ruby web applications

RUN_DEPENDS=	rubygem-gem_plugin>=0.2.3:${PORTSDIR}/devel/rubygem-gem_plugin \
		rubygem-daemons>=1.0.3:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-fastthread>=1.0.1:${PORTSDIR}/devel/rubygem-fastthread \
		rubygem-cgi_multipart_eof_fix>=2.4:${PORTSDIR}/www/rubygem-cgi_multipart_eof_fix

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/mongrel_rails

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN= does not compile with ruby 1.9
.endif
.include <bsd.port.post.mk>
