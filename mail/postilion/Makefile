# New ports collection makefile for:	postilion
# Version required:	0.9.1a
# Date created:		20 February 1999
# Whom:			Glenn Johnson <gljohns@bellsouth.net>
#
# $Id$
#

DISTNAME=	postilion-current
PKGNAME=	postilion-0.9.1a
CATEGORIES=	mail tk80
MASTER_SITES=	http://www.postilion.org/

MAINTAINER=	gljohns@bellsouth.net

LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80 \
		tkstep80.1:${PORTSDIR}/x11-toolkits/tkstep80 \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		img.1:${PORTSDIR}/graphics/libimg \
		Xpm.4:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80

FETCH_BEFORE_ARGS=	-b
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.0 \
		--with-tk-config=${PREFIX}/share/tkstep8.0

WRKSRC=		${WRKDIR}/postilion-0.9.1a
.include <bsd.port.mk>
