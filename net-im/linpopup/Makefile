# New ports collection makefile for:	linpopup
# Date created:		20 Nov 2000
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	linpopup
PORTVERSION=	1.2.0
PORTREVISION=	8
CATEGORIES=	net-im
MASTER_SITES=	http://www.chez.com/littleigloo/files/
DISTNAME=	LinPopUp-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 port of WinPopup

RUN_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/${SAMBA_PORT}

WRKSRC=		${WRKDIR}/LinPopUp-${PORTVERSION}/src

SAMBA_PORT?=	net/samba34

USE_XORG=	x11 xmu
USE_GNOME=	gtk12
ALL_TARGET=	LinPopUp

MLINKS=		LinPopUp.1 linpopup.1
MAN1=		LinPopUp.1

SUB_FILES=	pkg-message

.if defined(WITH_SAMBA3)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-samba3
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
