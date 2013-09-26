# Created by: ijliao
# $FreeBSD$

PORTNAME=	formosa
PORTVERSION=	0.2.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	lukhnos@gmail.com
COMMENT=	A collection of libraries for Taiwanese languages processing

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

RUN_DEPENDS=	rubygem-activesupport>=1.4.2:${PORTSDIR}/devel/rubygem-activesupport

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
