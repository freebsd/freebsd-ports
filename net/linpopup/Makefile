# New ports collection makefile for:	linpopup
# Date created:		20 Nov 2000
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	linpopup
PORTVERSION=	1.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://littleigloo.org/pub/linpopup/
DISTNAME=	LinPopUp-${PORTVERSION}.src

MAINTAINER=	roman@xpert.com

RUN_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/net/samba

WRKSRC=		${WRKDIR}/LinPopUp-${PORTVERSION}/src
ALL_TARGET=
MAN1=		linpopup.1 LinPopUp.1

USE_GTK=	yes
USE_X_PREFIX=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
