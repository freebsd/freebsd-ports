# New ports collection makefile for:	DocBook XML DTD
# Date created:		28 March 1999
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	docbook-xml
PORTVERSION=	4.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/xml/4.1.2/
DISTNAME=	docbkx412

MAINTAINER=	kuriyama@FreeBSD.org

USE_ZIP=	YES
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

INSTDIR=	${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/docbook
ENTDIR=		${INSTDIR}/docbook/ent
DTDFILES=	calstblx.dtd dbcentx.mod dbgenent.mod dbhierx.mod \
		dbnotnx.mod dbpoolx.mod docbookx.dtd soextblx.dtd
MISCFILES=	40chg.txt 41chg.txt readme.txt

post-extract:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/catalog.tmpl > ${WRKSRC}/catalog

pre-install:
	${MKDIR} ${ENTDIR}

do-install:
	@(cd ${WRKSRC};     ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	@(cd ${WRKSRC}/ent; ${INSTALL_DATA} *.ent ${ENTDIR})
	@(cd ${WRKSRC};     ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})
	${INSTALL_DATA} ${WRKSRC}/catalog ${INSTDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog.docbook ${DTDDIR}/catalog

.include <bsd.port.mk>
