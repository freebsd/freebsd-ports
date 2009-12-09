# New ports collection makefile for:	rubygem-net-sftp
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	net-sftp
PORTVERSION=	2.0.3
CATEGORIES=	security rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	net-ssh

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Implementation of the SFTP client protocol

RUN_DEPENDS=	rubygem-net-ssh>=2.0.2:${PORTSDIR}/security/rubygem-net-ssh

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=  yes

.include <bsd.port.mk>
