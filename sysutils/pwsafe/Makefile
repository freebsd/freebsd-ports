# New ports collection makefile for:	pwsafe
# Date created:				29 Mars 2004
# Whom:					donnex
#
# $FreeBSD$
#

PORTNAME=	pwsafe
PORTVERSION=	0.1.6
CATEGORIES=	sysutils
MASTER_SITES=	http://nsd.dyndns.org/pwsafe/releases/

MAINTAINER=	donnex@donnex.net
COMMENT=	Cmdline program that manages encrypted password databases

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		pwsafe.1
PLIST_FILES=	bin/pwsafe

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.include <bsd.port.post.mk>
