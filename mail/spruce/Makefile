# New ports collection makefile for:	spruce
# Version required:   	0.4.8
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.3 1999/06/21 23:03:16 cpiazza Exp $
#

DISTNAME=	spruce-0.4.8
CATEGORIES=	mail
MASTER_SITES=	http://www.xtorshun.org/spruce/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spruce ${PREFIX}/bin

.include <bsd.port.mk>
