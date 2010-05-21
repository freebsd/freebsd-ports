# Ports collection makefile for:	rubygem-bundler
# Date created:				7 November 2009
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	bundler
PORTVERSION=	0.9.25
CATEGORIES=	sysutils rubygems
MASTER_SITES=	http://gemcutter.org/gems/

MAINTAINER=	gogolok+freebsd@gmail.com
COMMENT=	A tool that manages gem dependencies for ruby applications

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/bundle

# we care about not passing -A to allow HTTP redirects
FETCH_ARGS=	-pRr

.include <bsd.port.mk>
