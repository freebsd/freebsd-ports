# New ports collection makefile for:   xwhois
# Version required:    0.4.0
# Date created:        31 December 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

DISTNAME=	xwhois-0.4.0
CATEGORIES=	net
MASTER_SITES=	http://c64.org/~nr/ \
		http://www.goatnet.ml.org/ \
		ftp://sangis.kalix.net/pub/nr/xwhois/ \
		ftp://c64.org/pub/nr/xwhois/ \
		http://www.physics.adelaide.edu.au/~kkennawa/

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

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
