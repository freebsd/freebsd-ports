# New ports collection makefile for: wmmount
# Date created:		04 Janyary 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	wmmount
PORTVERSION=	1.0b2
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker afterstep
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
DISTNAME=	${PORTNAME}-1.0-beta2
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The freespace for Window Maker

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_IMAKE=	yes
USE_XORG=	xpm
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
.for file in system.wmmount.eg system.wmmount.sh
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/config/${file}
.endfor
.if exists(/etc/fstab)
	@${SH} ${WRKSRC}/config/system.wmmount.sh > ${WRKSRC}/system.wmmount
.else
	@${CP} ${WRKSRC}/config/system.wmmount.eg ${WRKSRC}/system.wmmount
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmmount ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/wmmount
	${INSTALL_DATA} ${WRKSRC}/system.wmmount ${PREFIX}/lib/X11/wmmount
.for image in blank.xpm cdrom.xpm floppy.xpm harddisk.xpm zip.xpm
	${INSTALL_DATA} ${WRKSRC}/lib/${image} ${PREFIX}/lib/X11/wmmount
.endfor

.include <bsd.port.mk>
