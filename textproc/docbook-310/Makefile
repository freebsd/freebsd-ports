# New ports collection makefile for:	docbook-310
# Date created:		7 April 1999
# Whom:			nik
#
# Based heavily on work by jfieber
#
# $FreeBSD$
#

PORTNAME=	docbook
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/sgml/3.1/
DISTNAME=	docbk31

MAINTAINER=	nik@FreeBSD.org
COMMENT=	V3.1 of the DocBook DTD, designed for technical documentation

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
USE_ZIP=	yes
NO_MTREE=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME}
PLIST_SUB+=	DTD_VERSION=${PORTVERSION} 
PLIST_SUB+=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

LATEST_LINK=	docbook-310

pre-su-install:
	@[ -d ${INSTDIR}/${PORTVERSION} ] || ${MKDIR} ${INSTDIR}/${PORTVERSION}

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}/${PORTVERSION}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/${PORTVERSION}/catalog
	@${ECHO_CMD} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/${PORTVERSION}/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/${PORTVERSION}/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${PORTNAME}/${PORTVERSION}/catalog

.include <bsd.port.mk>
