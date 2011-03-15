# New ports collection makefile for:	wmymail
# Date created:		27 August 2002
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmymail
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	mail x11
MASTER_SITES=	http://yath.mine.nu/wmymail/ \
		http://dockapps.org/files/65/96/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check inbox using a WindowMaker DockApp

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp
RUN_DEPENDS=	fetchmail:${PORTSDIR}/mail/fetchmail

NOMAN=
PLIST_FILES=	bin/wmymail

.include <bsd.port.mk>
