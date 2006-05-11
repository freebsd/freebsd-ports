# New ports collection makefile for:	linpopup
# Date created:		20 Nov 2000
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	linpopup
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://www.chez.com/littleigloo/files/
DISTNAME=	LinPopUp-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 port of WinPopup

RUN_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/net/samba

WRKSRC=		${WRKDIR}/LinPopUp-${PORTVERSION}/src
ALL_TARGET=
MAN1=		linpopup.1 LinPopUp.1

USE_GNOME=	gtk12
USE_X_PREFIX=	yes

.if defined(WITH_SAMBA3)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-samba3
.endif

post-patch:
	${REINPLACE_CMD} -e "s#/doc/#/share/doc/#" ${WRKSRC}/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
