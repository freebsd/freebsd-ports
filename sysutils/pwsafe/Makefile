# New ports collection makefile for:	pwsafe
# Date created:				29 Mars 2004
# Whom:					donnex
#
# $FreeBSD$
#

PORTNAME=	pwsafe
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://nsd.dyndns.org/pwsafe/releases/

MAINTAINER=	donnex@donnex.net
COMMENT=	Cmdline program that manages encrypted password databases

OPTIONS=	SETUID "Install setuid pwsafe binary" off

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	ice sm x11 xmu

MAN1=		pwsafe.1
PLIST_FILES=	bin/pwsafe

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwsafe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pwsafe.1 ${PREFIX}/man/man1
.if defined(WITH_SETUID)
	${CHMOD} u+s ${PREFIX}/bin/pwsafe
.endif

.include <bsd.port.post.mk>

