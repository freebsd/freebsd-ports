# New ports collection makefile for:	spruce
# Version required:   	0.4.8c
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	spruce-0.4.8c
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
