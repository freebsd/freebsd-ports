# New ports collection makefile for:   xwhois
# Date created:        31 December 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	xwhois
PORTVERSION=	0.4.2
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://c64.org/~nr/xwhois/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK-based frontend to the whois service (RFC954)

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xwhois ${PREFIX}/bin
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/docs/xwhois.servers ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xwhois.xpm ${DATADIR}/pixmaps
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README    ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/TODO ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
