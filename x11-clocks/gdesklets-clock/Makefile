# New ports collection makefile for:	gdesklets-clock
# Date created:				02 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	clock
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX= gdesklets-
DISTNAME=	clock-desklet-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	Various clock displays for Gnome 2.x

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes

NAME=		Clock
DATADIR=	${PREFIX}/share/gnome
LANG=		de fr pt sq sr sr@Latn sv

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/locale/${ii}/LC_MESSAGES/*.mo \
		${DATADIR}/gdesklets/Sensors/${NAME}/locale/${ii}/LC_MESSAGES/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.dat ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.xcf ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Displays/${NAME}/
	@${LN} -s ${DATADIR}/gdesklets/Displays/${NAME}/README \
		${DATADIR}/gdesklets/Sensors/${NAME}/README

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
