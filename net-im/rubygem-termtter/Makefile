# New ports collection makefile for:	rubygem-termtter
# Date created:		2009-07-12
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	termtter
PORTVERSION=	1.3.1
CATEGORIES=	net-im rubygems
MASTER_SITES=	RF/termtter

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A terminal based twitter client

BUILD_DEPENDS=	rubygem-rubytter>0:${PORTSDIR}/net/rubygem-rubytter \
		rubygem-termcolor>0:${PORTSDIR}/textproc/rubygem-termcolor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/kill_termtter \
		bin/termtter

.include <bsd.port.mk>
