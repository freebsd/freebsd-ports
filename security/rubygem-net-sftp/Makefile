# New ports collection makefile for:	rubygem-net-sftp
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	net-sftp
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	security rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	net-ssh

MAINTAINER=	r.s.a.vandomburg@nedforce.nl
COMMENT=	Implementation of the SFTP client protocol

RUN_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/net-ssh-1.1.2.gemspec:${PORTSDIR}/security/rubygem-net-ssh

USE_RUBY=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.mk>
