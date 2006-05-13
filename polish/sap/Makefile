# Ports collection makefile for: sap
# Date created:		Fri 9 July 2004
# Whom: 		Aleksander Fafula <alex@bsdguru.org>
#
# $FreeBSD$
#

PORTNAME=	sap
PORTVERSION=	0.2
CATEGORIES=	polish
MASTER_SITES=	http://www.bsdguru.org/sap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex@bsdguru.org
COMMENT=	A command line Polish-English and English-Polish dictionary

do-configure:
	@${REINPLACE_CMD} -e 's|PREFIX=/usr|PREFIX=${PREFIX}|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|#define DICTIONARIES_DIRECTORY "/usr/lib/sap/"|#define DICTIONARIES_DIRECTORY "${PREFIX}/lib/sap/"|g' ${WRKSRC}/src/configuration.h_UNIX

.include <bsd.port.mk>
