# New ports collection makefile for:	rubygem-net-sftp
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	net-sftp
PORTVERSION=	2.0.1
CATEGORIES=	security rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	net-ssh

MAINTAINER=	r.s.a.vandomburg@nedforce.nl
COMMENT=	Implementation of the SFTP client protocol

RUN_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/net-ssh-2.0.2.gemspec:${PORTSDIR}/security/rubygem-net-ssh

USE_RUBY=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.mk>
