# New ports collection makefile for:	ruby-tmpl
# Date created:		2001-08-22
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tmpl
PORTVERSION=	0.2.3
CATEGORIES=	www textproc ruby
MASTER_SITES=	SF/ruby-${PORTNAME}/ruby-${PORTNAME}/ruby-${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An online/offline templating system a la eRuby/ERb

DEPRECATED=	Doesn't work with Ruby 1.9
EXPIRATION_DATE=	2011-08-03

USE_RUBY=	yes

NO_BUILD=	yes

PLIST_FILES=	%%RUBY_SITELIBDIR%%/ruby-tmpl.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
