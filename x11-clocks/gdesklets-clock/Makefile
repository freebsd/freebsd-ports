# New ports collection makefile for:	gdesklets-clock
# Date created:				02 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gdesklets-clock
PORTVERSION=	0.32
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
DISTNAME=	clock-desklet-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	Various clock displays for Gnome 2.x

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NAME=		Clock

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}
	@${CP} ${WRKSRC}/*.display ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${CP} -Rp ${WRKSRC}/gfx ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${CP} -Rp ${WRKSRC}/${NAME} ${PREFIX}/share/gnome/gdesklets/Sensors/
	@${CP} ${WRKSRC}/README ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${LN} -s ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/README \
		${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/README

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
