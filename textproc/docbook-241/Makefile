#A New ports collection makefile for:	docbook
# Version required:	2.4.1
# Date created:		7 April 1997
# Whom:			nik
#
# Based heavily on work by jfieber.
#
# $Id: Makefile,v 1.1.1.1 1999/04/14 22:26:54 nik Exp $
#

DISTNAME=	docbook-241
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/davenport/
DISTFILES=	docbk241.tar.Z

MAINTAINER=	nik@FreeBSD.ORG

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

pre-install:
	@[ -d ${INSTDIR}/2.4.1 ] || ${MKDIR} ${INSTDIR}/2.4.1

do-install:
	@zcat ${DISTDIR}/docbk241.tar.Z |(cd ${INSTDIR}/2.4.1; pax -r)
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/2.4.1/catalog
	@echo "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/2.4.1/catalog
	@chmod ${SHAREMODE} ${INSTDIR}/2.4.1/*
	@/usr/sbin/chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
