# $FreeBSD$

PORTNAME=	htmltools
PORTVERSION=	1.10
CATEGORIES=	textproc www rubygems
MASTER_SITES=	RG
DISTNAME=	htmltools-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tools for parsing and manipulating HTML text in Ruby

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=  yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
