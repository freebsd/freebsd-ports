# New ports collection makefile for:	docbook
# Version required:	3.0
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $Id$
#

DISTNAME=	docbook-3.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/davenport/

MAINTAINER=	jfieber@FreeBSD.ORG

DISTFILES=	docbk241.tar.Z docbk30.tar.Z

NO_MTREE=       yes
NO_EXTRACT=     yes
NO_BUILD=       yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKDIR=      yes

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

pre-install:
	@[ -d ${INSTDIR}/2.4.1 ] || ${MKDIR} ${INSTDIR}/2.4.1
	@[ -d ${INSTDIR}/3.0 ] || ${MKDIR} ${INSTDIR}/3.0

do-install:
	@zcat ${DISTDIR}/docbk241.tar.Z |(cd ${INSTDIR}/2.4.1; pax -r)
	@${INSTALL_DATA} ${FILESDIR}/catalog241 ${INSTDIR}/2.4.1/catalog
	@echo "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/2.4.1/catalog
	@zcat ${DISTDIR}/docbk30.tar.Z |(cd ${INSTDIR}/3.0; pax -r)
	@${INSTALL_DATA} ${FILESDIR}/catalog30 ${INSTDIR}/3.0/catalog
	@echo "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/3.0/catalog
	@chmod ${SHAREMODE} ${INSTDIR}/2.4.1/*
	@chmod ${SHAREMODE} ${INSTDIR}/3.0/*
	@chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
