# New ports collection makefile for:	transfig
# Version required:	3.2
# Date created:		9 August 1996
# Whom:			chuckr@freebsd.org
#
# $Id: Makefile,v 1.14 1997/08/28 04:21:13 chuckr Exp $
#

DISTNAME=	transfig.3.2
PKGNAME=	transfig-3.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/transfig

MAINTAINER=	chuckr@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5 \
		ppmtogif:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes

.include <bsd.port.mk>
