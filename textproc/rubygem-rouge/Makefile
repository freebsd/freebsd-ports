# $FreeBSD$

PORTNAME=	rouge
PORTVERSION=	1.4.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Simple, easy-to-extend drop-in replacement for pygments

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rougify

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 2.1
BROKEN=		Does not build with Ruby 2.1
.endif

.include <bsd.port.post.mk>
