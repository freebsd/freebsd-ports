# New ports collection makefile for:	"Simplified" DocBook XML DTD
# Date created:		25 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdocbook-xml
PORTVERSION= 	4.1.2.5
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/simple/4.1.2.5/
DISTNAME=	simple${PORTVERSION:S/.//g}
EXTRACT_ONLY=	# empty

MAINTAINER=	des@FreeBSD.org

RUN_DEPENDS=    ${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	MKCATALOG=${MKCATALOG} CATALOG=${CATALOG}

SDOCBOOKDIR=	${PREFIX}/share/xml/sdocbook
MKCATALOG=      ${LOCALBASE}/sbin/mkcatalog
CATALOG=        ${PREFIX}/share/xml/catalog

do-install:
	${MKDIR} ${SDOCBOOKDIR}
	(cd ${SDOCBOOKDIR} && unzip -oq ${DISTDIR}/${DISTFILES})
	${INSTALL_DATA} ${FILESDIR}/catalog ${SDOCBOOKDIR}

post-install:
	${MKCATALOG} -q -c ${CATALOG} install sdocbook catalog

.include <bsd.port.mk>
