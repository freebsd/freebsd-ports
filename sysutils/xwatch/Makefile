# New ports collection makefile for:   	xwatch
# Version required:			0.1.0
# Date created:				17 July 1998
# Whom:					mph
#
# $Id: Makefile,v 1.1.1.1 1998/07/17 17:41:17 mph Exp $
#

DISTNAME=	xwatch-0.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://hem.passagen.se/osk/

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	gtk\\.1:${PORTSDIR}/x11-toolkits/gtk

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/doc/xwatch.test.conf ${PREFIX}/share/doc/xwatch
.endif

.include <bsd.port.mk>
