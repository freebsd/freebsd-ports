# New ports collection makefile for:	ruby-tmpl
# Date created:		2001-08-22
# Whom:			Sean Chittenden <sean@chittenden.org>
#
# $FreeBSD$
#

PORTNAME=	tmpl
PORTVERSION=	0.2.2
CATEGORIES=	www textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	sean@chittenden.org

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb

.include <bsd.port.mk>
