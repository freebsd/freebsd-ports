# New ports collection makefile for:	xloadface
# Version required:	1.6.1
# Date created:		4 February 1998
# Whom:			FURUSAWA,Kazuhisa <kazu@jp.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	xloadface-1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.waseda.ac.jp/pub/X11others/

MAINTAINER=	kazu@jp.freebsd.org

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

PATCH_STRIP= 	-p1
USE_IMAKE=	yes
XLOADFACEDIR=	$(X11BASE)/lib/X11/xloadface

MAN1=		xloadface.1

pre-install:
	@nkf -e ${WRKSRC}/xloadface.1 > ${WRKSRC}/xloadface.man
	${MKDIR} $(XLOADFACEDIR)
	${INSTALL_DATA} ${WRKSRC}/README $(XLOADFACEDIR)
	${INSTALL_DATA} ${WRKSRC}/host_org.sample $(XLOADFACEDIR)
	${MKDIR} $(XLOADFACEDIR)/bigfaces
	${MKDIR} $(XLOADFACEDIR)/bitmap
	${MKDIR} $(XLOADFACEDIR)/catfaces
	${INSTALL_DATA} ${WRKSRC}/bigfaces/* $(XLOADFACEDIR)/bigfaces
	${INSTALL_DATA} ${WRKSRC}/bitmap/*   $(XLOADFACEDIR)/bitmap
	${INSTALL_DATA} ${WRKSRC}/catfaces/* $(XLOADFACEDIR)/catfaces

.include <bsd.port.mk>
