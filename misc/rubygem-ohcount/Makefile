# Created by: Edmondas Girkantas <eg@fbsd.lt>
# $FreeBSD$

PORTNAME=	ohcount
PORTVERSION=	2.0.1
CATEGORIES=	misc rubygems
MASTER_SITES=	http://labs.ohloh.net/download/

MAINTAINER=	eg@fbsd.lt
COMMENT=	Ohcount is the source code line counter that powers Ohloh

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

RUN_DEPENDS=	rubygem-diff-lcs>=1.1.2:${PORTSDIR}/textproc/rubygem-diff-lcs \
		ragel:${PORTSDIR}/devel/ragel

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ohcount

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
