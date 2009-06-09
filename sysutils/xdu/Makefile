# New ports collection makefile for:	xdu
# Date created:		9 February 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xdu
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://sd.wareonearth.com/~phil/xdu/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphically display output of du

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
PLIST_FILES=	bin/xdu lib/X11/app-defaults/XDu
MAN1=		xdu.1

.include <bsd.port.mk>
