# New ports collection makefile for:   xwhois
# Version required:    0.3.4
# Date created:        31 December 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id: Makefile,v 1.3 1999/03/01 10:51:39 kris Exp $
#

DISTNAME=	xwhois-0.3.4
CATEGORIES=	net
MASTER_SITES=	http://c64.org/~nr/ \
		http://www.goatnet.ml.org/ \
		ftp://sangis.kalix.net/pub/nr/xwhois/ \
		ftp://c64.org/pub/nr/xwhois/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/xwhois/ \
		http://www.physics.adelaide.edu.au/~kkennawa/

MAINTAINER=	kris@FreeBSD.ORG

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xwhois ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/xwhois
	${MKDIR} ${PREFIX}/share/xwhois/pixmaps
	${INSTALL_DATA} ${WRKSRC}/docs/xwhois.servers ${PREFIX}/share/xwhois
	${INSTALL_DATA} ${WRKSRC}/docs/xwhois.xpm ${PREFIX}/share/xwhois/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xwhois
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xwhois
	${INSTALL_DATA} ${WRKSRC}/docs/TODO ${PREFIX}/share/doc/xwhois
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xwhois
.endif

.include <bsd.port.mk>
