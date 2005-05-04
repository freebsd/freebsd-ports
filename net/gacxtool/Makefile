# New ports collection makefile for:	gacxtool
# Date created:		2004-11-14
# Whom:			Leonid Zolotarev <leoz.2005@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gacxtool
PORTVERSION=	0.1.0
CATEGORIES=	net
MASTER_SITES=	http://www.leoz.myoptimus.com/gacxtool/files/

MAINTAINER=	leoz.2005@gmail.com
COMMENT=	Displays the status of the ACX driver

LIB_DEPENDS=	gtkdatabox:${PORTSDIR}/x11-toolkits/gtkdatabox2
BUILD_DEPENDS=	/boot/kernel/if_acx.ko:${PORTSDIR}/net/acx100
RUN_DEPENDS=	/boot/kernel/if_acx.ko:${PORTSDIR}/net/acx100

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes

.include <bsd.port.mk>
