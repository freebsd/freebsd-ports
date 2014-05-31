# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sshkit
PORTVERSION=	1.5.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for remotely running commands on groups of servers

LICENSE=	GPLv3

RUN_DEPENDS=	rubygem-colorize>=0:${PORTSDIR}/devel/rubygem-colorize \
		rubygem-net-scp>=1.1.2:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-ssh>=2.8.0:${PORTSDIR}/security/rubygem-net-ssh

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
