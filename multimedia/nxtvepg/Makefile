# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	nxtvepg
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	multimedia tcl tk
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for Nextview Electronic TV Programme Guide (needs bktr driver)

NOT_FOR_ARCHS=	sparc64
USES=		gmake tk:84
USE_XORG=	x11 xmu
MAKE_ARGS=	ROOT=${STAGEDIR}
MAKE_ENV=	PTHREAD_LIBS="-lpthread" WRKSRC="${WRKSRC}" \
		X11BASE="${LOCALBASE}"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s,machine/ioctl_bt848.h,dev/bktr/ioctl_bt848.h,; \
		s,machine/ioctl_meteor.h,dev/bktr/ioctl_meteor.h," \
		${WRKSRC}/epgvbi/btdrv4linux.c ${WRKSRC}/tvsim/tvsim_main.c
	@${REINPLACE_CMD} 's|wait.h|sys/&|' ${WRKSRC}/epgdb/ttxgrab.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nxtvepg ${STAGEDIR}${PREFIX}/bin/nxtvepgd
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README TODO CHANGES manual.html \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
