# New ports collection makefile for:    Mosaic browser
# Date created:         7 August 1995
# Whom:                 torstenb
#
# $FreeBSD$
#

PORTNAME=	mosaic
PORTVERSION=	2.7b5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/
DISTNAME=	Mosaic-src-2.7b5

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

NO_CDROM=	"http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/License/LicenseInfo.html"
NO_PACKAGE=	${NO_CDROM}
USE_MOTIF=	yes
WRKSRC=		${WRKDIR}/Mosaic-src
ALL_TARGET=	bsdi
USE_X_PREFIX=	yes
USE_XPM=	yes

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
	${WRKSRC}/libXmx/Xmx.h ${WRKSRC}/libdtm/dtm.c \
	${WRKSRC}/libdtm/dtm.c ${WRKSRC}/libdtm/dtm.c \
	${WRKSRC}/libdtm/dtm.c ${WRKSRC}/libdtm/dtminit.c \
	${WRKSRC}/libdtm/dtminit.c ${WRKSRC}/libdtm/dtminit.c \
	${WRKSRC}/libdtm/dtminit.c ${WRKSRC}/libdtm/dtmnserv.c \
	${WRKSRC}/libdtm/dtmnserv.c ${WRKSRC}/libhtmlw/HTML-PSformat.c \
	${WRKSRC}/libhtmlw/HTML-PSformat.c ${WRKSRC}/libwww2/HTUtils.h \
	${WRKSRC}/libwww2/HTUtils.h ${WRKSRC}/src/mosaic.h \
	${WRKSRC}/src/mosaic.h ${WRKSRC}/src/proxy-dialogs.c \
	${WRKSRC}/src/proxy-dialogs.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Mosaic ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/app-defaults.color ${PREFIX}/lib/X11/app-defaults/Mosaic

.include <bsd.port.mk>
