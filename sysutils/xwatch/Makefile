# New ports collection makefile for:   	xwatch
# Version required:			0.1.0
# Date created:				17 July 1998
# Whom:					mph
#
# $Id: Makefile,v 1.4 1998/09/22 22:55:55 asami Exp $
#

DISTNAME=	xwatch-0.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://hem.passagen.se/osk/

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk11-config"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/doc/xwatch.test.conf ${PREFIX}/share/doc/xwatch
.endif

.include <bsd.port.mk>
