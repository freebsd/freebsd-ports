#A New ports collection makefile for:	docbook
# Date created:		7 April 1997
# Whom:			nik
#
# Based heavily on work by jfieber.
#
# $FreeBSD$
#

PORTNAME=	docbook
PORTVERSION=	241
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/davenport/
DISTFILES=	docbk241.tar.Z

MAINTAINER=	nik@FreeBSD.org
COMMENT=	V2.4.1 of the DocBook DTD, designed for technical documentation

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_MTREE=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME}
PLIST_SUB+=	DTD_VERSION=${DTD_VERSION}
PLIST_SUB+=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
DTD_VERSION=	2.4.1

LATEST_LINK=	docbook-241

pre-su-install:
	@[ -d ${INSTDIR}/${DTD_VERSION} ] || ${MKDIR} ${INSTDIR}/${DTD_VERSION}

do-install:
	@zcat ${DISTDIR}/docbk241.tar.Z | \
		(cd ${INSTDIR}/${DTD_VERSION}; ${PAX} -r)
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/${DTD_VERSION}/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/${DTD_VERSION}/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/${DTD_VERSION}/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${PORTNAME}/${DTD_VERSION}/catalog

.include <bsd.port.mk>
