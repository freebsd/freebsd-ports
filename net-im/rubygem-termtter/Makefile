# New ports collection makefile for:	rubygem-termtter
# Date created:		2009-07-12
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	termtter
PORTVERSION=	1.8.0
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A terminal based twitter client

RUN_DEPENDS=	rubygem-json>=1.1.3:${PORTSDIR}/devel/rubygem-json \
		rubygem-termcolor>=1.0.0:${PORTSDIR}/textproc/rubygem-termcolor \
		rubygem-rubytter>=0.11.0:${PORTSDIR}/net/rubygem-rubytter \
		rubygem-highline>1.5.0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-notify>=0.2.1:${PORTSDIR}/devel/rubygem-notify

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES= bin/termtter

.include <bsd.port.mk>
