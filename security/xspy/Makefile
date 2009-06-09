# Ports collection makefile for:  xspy
# Date created:			  Jan 11 2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xspy
PORTVERSION=	1.0c
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.acm.vt.edu/~jmaxwell/programs/xspy/

MAINTAINER=	onatan@gmail.com
COMMENT=	A utility for monitoring keystrokes on remote X servers

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XORG=	x11
XMKMF=		xmkmf

ALL_TARGET=	xspy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xspy ${PREFIX}/bin

.include <bsd.port.mk>
