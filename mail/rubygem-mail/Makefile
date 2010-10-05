# Ports collection makefile for:	rubygem-mail
# Date created:				30 Aug 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	mail
PORTVERSION=	2.2.6
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	A Ruby email handler

RUN_DEPENDS=	rubygem-treetop>=1.4.5:${PORTSDIR}/devel/rubygem-treetop \
		rubygem-mime-types>=0:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-activesupport>=2.3.6:${PORTSDIR}/devel/rubygem-activesupport

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
