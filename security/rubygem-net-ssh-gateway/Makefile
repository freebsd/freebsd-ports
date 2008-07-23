# New ports collection makefile for:	rubygem-net-ssh-gateway
# Date created:				June 27, 2008
# Whom:					Philip M. Gollucci <pgollucci@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	net-ssh-gateway
PORTVERSION=	1.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	net-ssh

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Establish Net::SSH connections through firewalls

RUN_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/net-ssh-2.0.2.gemspec:${PORTSDIR}/security/rubygem-net-ssh

USE_RUBY=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.mk>
