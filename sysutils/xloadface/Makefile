# New ports collection makefile for:	xloadface
# Version required:	1.6.1
# Date created:		28 November 1996
# Whom:			FURUSAWA,Kazuhisa <furusawa@com.cs.osakafu-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/12/03 13:21:31 obrien Exp $
#

DISTNAME=	xloadface-1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.waseda.ac.jp/pub/X11others/

MAINTAINER=	furusawa@com.cs.osakafu-u.ac.jp

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

PATCH_STRIP= 	-p1
USE_IMAKE=	yes
XLOADFACEDIR=	$(X11BASE)/lib/X11/xloadface

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
