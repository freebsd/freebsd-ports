# New ports collection makefile for:	wmymail
# Date created:		27 August 2002
# Whom:			Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$

PORTNAME=	wmymail
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	mail x11
MASTER_SITES=	http://yath.mine.nu/wmymail/ \
		http://dockapps.org/files/65/96/

MAINTAINER=	bms@spc.org
COMMENT=	Check inbox using a WindowMaker DockApp

LIB_DEPENDS=	dockapp.1:${PORTSDIR}/x11-wm/libdockapp
RUN_DEPENDS=	fetchmail:${PORTSDIR}/mail/fetchmail

USE_X_PREFIX=	yes

NOMAN=
PLIST_FILES=	bin/wmymail

.include <bsd.port.mk>
