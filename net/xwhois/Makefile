# New ports collection makefile for:   xwhois
# Version required:    0.2.9
# Date created:        31 December 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id$
#

DISTNAME=	xwhois-0.2.9
CATEGORIES=	net
MASTER_SITES=	http://c64.org/~nr/ \
		http://www.goatnet.ml.org/ \
		ftp://sangis.kalix.net/pub/nr/xwhois/ \
		ftp://c64.org/pub/nr/xwhois/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/xwhois/

MAINTAINER=	kkennawa@physics.adelaide.edu.au

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_X_PREFIX=	yes

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/xwhois ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/xwhois
	${MKDIR} ${PREFIX}/share/xwhois/pixmaps
	${INSTALL_DATA} ${WRKSRC}/xwhois.servers ${PREFIX}/share/xwhois
	${INSTALL_DATA} ${WRKSRC}/xwhois.xpm ${PREFIX}/share/xwhois/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xwhois
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xwhois
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/xwhois
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xwhois
.endif

.include <bsd.port.mk>
