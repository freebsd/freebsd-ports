# New ports collection makefile for:   	xwatch
# Date created:				17 July 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	xwatch
PORTVERSION=	0.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://hem.passagen.se/osk/

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/doc/xwatch.test.conf ${PREFIX}/share/doc/xwatch
.endif

.include <bsd.port.mk>
