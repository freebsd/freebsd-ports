# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ferret
PORTVERSION=	0.11.6
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ferret is a ruby port of Lucene

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=  yes
PLIST_FILES=	bin/ferret-browser

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
