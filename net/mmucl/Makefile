# New ports collection Makefile for:	mmucl
# Date created:				28 July 2000
# Whom:					Matt Heckaman <matt@LUCIDA.QC.CA>
#
# $FreeBSD$
#

PORTNAME=	mmucl
PORTVERSION=	1.4.1
CATEGORIES=	net
MASTER_SITES=	http://download.sourceforge.net/mmucl/

MAINTAINER=	matt@LUCIDA.CA

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

USE_GMAKE=	YES

post-install:
	${MKDIR} ${PREFIX}/share/doc/${DISTNAME}
	${MKDIR} ${PREFIX}/share/doc/${DISTNAME}/examples
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/doc/${DISTNAME}/examples

.include <bsd.port.mk>
