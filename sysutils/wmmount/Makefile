# New ports collection makefile for: wmmount
# Date created:		04 Janyary 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	wmmount
PORTVERSION=	1.0b1
CATEGORIES=	sysutils windowmaker afterstep
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
DISTNAME=	wmmount-1.0-beta1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ozz@FreeBSD.org.ru

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wmmount
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-extract:
	@ if [ -r /etc/fstab ]; then \
		${WRKSRC}/system.wmmount.awk >${WRKSRC}/system.wmmount; \
	  else \
		${CP} ${WRKSRC}/system.wmmount.eg ${WRKSRC}/system.wmmount; \
	  fi

do-install:
	@ ${MKDIR} ${PREFIX}/lib/X11/wmmount
	@ ${INSTALL_PROGRAM} ${WRKSRC}/wmmount ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/system.wmmount ${PREFIX}/lib/X11/wmmount
.for image in blank.xpm cdrom.xpm floppy.xpm harddisk.xpm zip.xpm
	@ ${INSTALL_DATA} ${WRKSRC}/EXTRAS/${image} ${PREFIX}/lib/X11/wmmount
.endfor

.include <bsd.port.mk>
