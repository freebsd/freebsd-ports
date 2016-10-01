# $FreeBSD$

PORTNAME=	string-scrub
PORTVERSION=	0.0.5
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	String\#scrub for Ruby 2.0.0 and 1.9.3

LICENSE=	MIT

DEPRECATED=	needed only for EOL versions of Ruby
EXPIRATION_DATE=	2016-11-01

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.1
BROKEN=		Needed for Ruby 1.9.x/2.0.x only
.endif

.include <bsd.port.post.mk>
