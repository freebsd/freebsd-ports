# New ports collection makefile for:   xwhois
# Date created:        31 December 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	xwhois
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://c64.org/~nr/xwhois/dist/

MAINTAINER=	billf@FreeBSD.org
COMMENT=	A GTK-based frontend to the whois service (RFC954)

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

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
