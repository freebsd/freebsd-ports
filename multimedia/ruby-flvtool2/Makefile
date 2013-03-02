# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	flvtool2
PORTVERSION=	1.0.6
CATEGORIES=	multimedia ruby
MASTER_SITES=	RUBYFORGE
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	ruby-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	Manipulation tool for Macromedia Flash Video files

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2012-05-02

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
