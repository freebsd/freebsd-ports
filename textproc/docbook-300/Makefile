# New ports collection makefile for:	docbook-300
# Version required:	3.0
# Date created:		7 April 1999
# Whom:			nik
#
# Based heavily on work by jfieber
#
# $FreeBSD$
#

DISTNAME=	docbook-3.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/davenport/
DISTFILES=	docbk30.tar.Z

MAINTAINER=	nik@FreeBSD.org

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

pre-install:
	@[ -d ${INSTDIR}/3.0 ] || ${MKDIR} ${INSTDIR}/3.0

do-install:
	@zcat ${DISTDIR}/docbk30.tar.Z |(cd ${INSTDIR}/3.0; pax -r)
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/3.0/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/3.0/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/3.0/*
	@${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
