# New ports collection makefile for:	nxtvepg-2.4.2
# Date created:		07 Jan 2003
# Whom:			Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	nxtvepg
PORTVERSION=	2.7.6
PORTREVISION=	2
CATEGORIES=	multimedia tcl tk
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for Nextview Electronic TV Programme Guide (needs bktr driver)

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

NOT_FOR_ARCHS=	sparc64
USE_GMAKE=	yes
USE_XORG=	x11 xmu
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} WRKSRC=${WRKSRC}

MAN1=		nxtvepg.1
MYPORTDOCS=	README TODO CHANGES manual.html

post-patch:
	${REINPLACE_CMD} -e "s,machine/ioctl_bt848.h,dev/bktr/ioctl_bt848.h,; \
		s,machine/ioctl_meteor.h,dev/bktr/ioctl_meteor.h," \
		${WRKSRC}/epgvbi/btdrv4linux.c ${WRKSRC}/tvsim/tvsim_main.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nxtvepg ${LOCALBASE}/bin
	${INSTALL_DATA}    ${WRKSRC}/Nxtvepg.ad ${LOCALBASE}/lib/X11/app-defaults/Nxtvepg
	${INSTALL_MAN}     ${WRKSRC}/nxtvepg.1 ${LOCALBASE}/man/man1

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
