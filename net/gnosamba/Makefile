# New ports collection makefile for:	gnosamba
# Date created:				4 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gnosamba
PORTVERSION=	0.3.3
CATEGORIES=	net gnome
MASTER_SITES=	http://linuxberg.ii.net/files/gnome/network/ \
		http://www.open-systems.com/gnosamba/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
