# New ports collection makefile for:	DocBook XML DTD
# Version required:	3.1.7
# Date created:		28 March 1999
# Whom:			kuriyama
#
# $FreeBSD$
#

DISTNAME=	db3x317
PKGNAME=	docbook-xml-3.1.7
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/xml/3.1.7/

MAINTAINER=	kuriyama@FreeBSD.org

USE_ZIP=	YES
NO_MTREE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTDIR=	${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/dtd/docbook
ENTDIR=		${INSTDIR}/entity
MISCDIR=	${INSTDIR}/misc/docbook
DTDFILES=	calstblx.dtd dbcentx.mod dbgenent.ent dbhierx.mod \
		dbnotnx.mod dbpoolx.mod docbookx.dtd soextblx.dtd
MISCFILES=	COPYRIGHT ChangeLog README VERSION test.xml

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@[ -d ${DTDDIR}	 ] || ${MKDIR} ${DTDDIR}
	@[ -d ${ENTDIR}	 ] || ${MKDIR} ${ENTDIR}
	@[ -d ${MISCDIR} ] || ${MKDIR} ${MISCDIR}

do-install:
	@(cd ${WRKSRC};     ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	@(cd ${WRKSRC}/ent; ${INSTALL_DATA} *.ent ${ENTDIR})
	@(cd ${WRKSRC};     ${INSTALL_DATA} ${MISCFILES} ${MISCDIR})

.include <bsd.port.mk>
