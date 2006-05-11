# New ports collection makefile for:	ccmsn
# Date created:		07 April 2002
# Whom:		Sergio Jimenez Romero  (aka TripleDES) <TripleDES@eSlack.org>
#
# $FreeBSD$
#

PORTNAME=	ccmsn
PORTVERSION=	0.3p3
CATEGORIES=	net-im
MASTER_SITES=	http://msn.CompuCreations.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jimromse@eupmt.es
COMMENT=	A Tcl/Tk-based MSN messenger

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin/wish|${LOCALBASE}/bin/wish8.3|" \
		-e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/ccmsn

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ccmsn ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/i
	${INSTALL_SCRIPT} ${WRKSRC}/migmd5.tcl ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
	${CP} ${WRKSRC}/i/* ${DATADIR}/i

.include <bsd.port.mk>
