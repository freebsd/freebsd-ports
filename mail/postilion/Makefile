# New ports collection makefile for:	postilion
# Date created:		20 February 1999
# Whom:			Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	postilion
PORTVERSION= 	0.9.3c
CATEGORIES=	mail tk82
MASTER_SITES=	http://www.postilion.org/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		img.1:${PORTSDIR}/graphics/libimg
BUILD_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82

FETCH_BEFORE_ARGS=	-b
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.2

#.if defined(STEPIFY)
#LIB_DEPENDS+=	tkstep80.1:${PORTSDIR}/x11-toolkits/tkstep80 \
#		Dnd.1:${PORTSDIR}/x11/libdnd \
#		tiff.4:${PORTSDIR}/graphics/tiff \
#		jpeg.9:${PORTSDIR}/graphics/jpeg \
#		Xpm.4:${PORTSDIR}/graphics/xpm
#CONFIGURE_ARGS+= --with-tk-config=${PREFIX}/lib/tkstep8.0
#pre-patch:
#	${SED} s/'(DND) 0/(DND) 1'/ ${FILESDIR}/options.tcl > \
#	${WRKSRC}/postilion/options.tcl
#.else
#pre-extract:
#	@${ECHO} ""
#	@${ECHO} "You can build postilion with NeXtStep style widgets by defining STEPIFY"
#	@${ECHO} ""
LIB_DEPENDS+=	tk82.1:${PORTSDIR}/x11-toolkits/tk82
CONFIGURE_ARGS+= --with-tk-config=${PREFIX}/lib/tk8.2
#.endif

.include <bsd.port.mk>
