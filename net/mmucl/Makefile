# New ports collection Makefile for:	mmucl
# Date created:				28 July 2000
# Whom:					Matt Heckaman <matt@LUCIDA.QC.CA>
#
# $FreeBSD$
#

PORTNAME=	mmucl
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.sourceforge.net/mmucl/

MAINTAINER=	tim@SPYDERWEB.COM.AU
COMMENT=	Powerful GUI MUD client written in TCL

LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_GMAKE=	YES
INFO=		mmucl

post-install:
	${MKDIR} ${PREFIX}/share/doc/${DISTNAME}
	${MKDIR} ${PREFIX}/share/doc/${DISTNAME}/examples
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/doc/${DISTNAME}/examples

.include <bsd.port.mk>
