# New ports collection makefile for:	postilion
# Version required:	0.9.1a
# Date created:		20 February 1999
# Whom:			Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

DISTNAME=	postilion-0.9.2
CATEGORIES=	mail tk80
MASTER_SITES=	http://www.postilion.org/

MAINTAINER=	gljohns@bellsouth.net

LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80 \
		img.1:${PORTSDIR}/graphics/libimg
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80

FETCH_BEFORE_ARGS=	-b
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.0

.if defined(STEPIFY)
LIB_DEPENDS+=	tkstep80.1:${PORTSDIR}/x11-toolkits/tkstep80 \
		Dnd.1:${PORTSDIR}/x11/libdnd \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		Xpm.4:${PORTSDIR}/graphics/xpm
CONFIGURE_ARGS+= --with-tk-config=${PREFIX}/lib/tkstep8.0
pre-patch:
	${SED} s/'(DND) 0/(DND) 1'/ ${FILESDIR}/options.tcl > \
	${WRKSRC}/postilion/options.tcl
.else
pre-extract:
	@${ECHO} ""
	@${ECHO} "You can build postilion with NeXtStep style widgets by defining STEPIFY"
	@${ECHO} ""
LIB_DEPENDS+=	tk80.1:${PORTSDIR}/x11-toolkits/tk80
CONFIGURE_ARGS+= --with-tk-config=${PREFIX}/lib/tk8.0
.endif

.include <bsd.port.mk>
