# New ports collection makefile for:    hp2xx
# Date created:         17 Jan 1999
# Whom:                 Lars Koeller
#
# $FreeBSD$
#

PORTNAME=	hp2xx
PORTVERSION=	3.4.4
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE
COMMENT=	A HPGL to vector- and raster formats converter and previewer for X11

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${DISTNAME}/sources

USE_GETOPT_LONG=	yes
MAKE_ENV=	DEFINES="${CPPFLAGS}" ALL_LIBS="${LDFLAGS}" \
		PREVIEWER="${PREVIEWER}" 

MAN1=		hp2xx.1

CPPFLAGS=	-DUNIX -I${LOCALBASE}/include
LDFLAGS=	-lm -L${LOCALBASE}/lib -ltiff -lpng -lz

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
PREVIEWER=	no_prev
.else
USE_XLIB=	yes
CPPFLAGS+=	-DHAS_UNIX_X11 -I${X11BASE}/include
LDFLAGS+=	-L${X11BASE}/lib -lX11
PREVIEWER=	to_x11
.endif

post-install:
.for info in hp2xx.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
