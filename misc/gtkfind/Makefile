# New ports collection makefile for:	gtkfind
# Date created:				28 Sept 1998
# Whom:					Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	gtkfind
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	billf@FreeBSD.org
COMMENT=	The program to use to have to remember all the options to find(1)

BUILD_DEPENDS=	xterm:${PORTSDIR}/x11/XFree86-4-clients

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		gtkfind.1

post-patch:
	${REINPLACE_CMD} -e "s,-O2,${CFLAGS}," ${WRKSRC}/configure ${WRKSRC}/Makefile.in	

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkfind ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gtkfind.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
