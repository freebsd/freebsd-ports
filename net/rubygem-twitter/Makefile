# ex:ts=8
# Ports collection makefile for:	rubygem-twitter
# Date created:			Apr 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twitter
PORTVERSION=	0.2.1
CATEGORIES=	net rubygems
MASTER_SITES=	RF

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Command line twits and an API wrapper

BUILD_DEPENDS=	rubygem-hpricot>0:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-hoe>=1.2.0:${PORTSDIR}/devel/rubygem-hoe \
		rubygem-activesupport>0:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/twitter

.include <bsd.port.mk>
