# New ports collection makefile for:	spruce
# Version required:   	0.4.8a
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.6 1999/07/14 02:41:15 obrien Exp $
#

DISTNAME=	spruce-0.4.8a
CATEGORIES=	mail
#main master site unreachable: MASTER_SITES=	http://www.xtorshun.org/spruce/
MASTER_SITES=	http://fundy.linuxberg.com/files/x11/network/ \
		ftp://ftp.loxinfo.co.th/pub/unix/mail/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
USE_GMAKE=	yes

.include <bsd.port.mk>
