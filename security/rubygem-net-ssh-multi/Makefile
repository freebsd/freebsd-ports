# New ports collection makefile for:	rubygem-net-ssh-multi
# Date created:				02 May 2011
# Whom:					Renaud Chaput <renchap@cocoa-x.com>
#
# $FreeBSD$
#

PORTNAME=	net-ssh-multi
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	SSH connection multiplexing library for Ruby

RUN_DEPENDS=	rubygem-net-ssh>=1.99.2:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-ssh-gateway>=0.99.0:${PORTSDIR}/security/rubygem-net-ssh-gateway

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
