# New ports collection makefile for:	spruce
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spruce
PORTVERSION= 	0.4.9f
CATEGORIES=	mail
MASTER_SITES=	http://www.xtorshun.org/spruce/ \
		http://fundy.linuxberg.com/files/x11/network/ \
		ftp://ftp.loxinfo.co.th/pub/unix/mail/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
USE_GMAKE=	yes

.include <bsd.port.mk>
