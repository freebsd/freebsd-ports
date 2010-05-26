# Ports collection makefile for:	gem-actionmailer
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionmailer
PORTVERSION=	2.3.8
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy email delivery and testing for Ruby

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/actionpack-${PORTVERSION}.gemspec:${PORTSDIR}/www/rubygem-actionpack
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
