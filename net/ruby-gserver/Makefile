# New ports collection makefile for:	GServer.rb
# Date created:		12 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gserver
PORTVERSION=	0.0.0
CATEGORIES=	net ruby
MASTER_SITES=	http://www.ruby-lang.org/~knu/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	GServer.rb-${PORTVERSION}
EXTRACT_SUFX=	# none
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	.

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${RUBY_SITELIBDIR}/GServer.rb

.include <bsd.port.mk>
