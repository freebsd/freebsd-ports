# New ports collection makefile for:	ruby-tmpl
# Date created:		2001-08-22
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tmpl
PORTVERSION=	0.2.3
CATEGORIES=	www textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An online/offline templating system a la eRuby/ERb

USE_RUBY=	yes

NO_BUILD=	yes

PLIST_FILES=	%%RUBY_SITELIBDIR%%/ruby-tmpl.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

.include <bsd.port.mk>
