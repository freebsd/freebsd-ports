# New ports collection makefile for:	transfig
# Version required:	3.1.2
# Date created:		9 August 1996
# Whom:			chuckr@freebsd.org
#
# $Id: Makefile,v 1.10 1996/08/11 02:42:59 chuckr Exp $
#

DISTNAME=	transfig.3.1.2
PKGNAME=	transfig-3.1.2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/drawing_tools/transfig/ \
	ftp://crl.dec.com/pub/X11/contrib/applications/drawing_tools/transfig/

MAINTAINER=	chuckr@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg

USE_IMAKE=	yes

.include <bsd.port.mk>

