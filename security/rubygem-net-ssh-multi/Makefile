# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	net-ssh-multi
PORTVERSION=	1.2.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	SSH connection multiplexing library for Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ssh>=2.6.5:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-ssh-gateway>=1.2.0:${PORTSDIR}/security/rubygem-net-ssh-gateway

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
