# Ports collection makefile for:	gem-actionpack
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	actionpack
PORTVERSION=	2.3.2
CATEGORIES=	www rubygems
MASTER_SITES=	RF

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Action Controller and Action View of Rails MVC Framework

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-2.3.2.gemspec:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
