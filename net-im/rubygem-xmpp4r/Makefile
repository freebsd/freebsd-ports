# Created by: Stephan Maka <stephan@spaceboyz.net>
# $FreeBSD$

PORTNAME=	xmpp4r
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	net-im ruby rubygems
MASTER_SITES=	RG

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	XMPP/Jabber library for Ruby

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
