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
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/davenport/
DISTFILES=	docbk241.tar.Z

MAINTAINER=	nik@FreeBSD.org

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

NO_MTREE=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME} DTD_VERSION=2.4.1 MKCATALOG=${MKCATALOG}

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog
MKCATALOG=	${PREFIX}/sbin/mkcatalog

LATEST_LINK=	docbook-241

pre-install:
	@[ -d ${INSTDIR}/2.4.1 ] || ${MKDIR} ${INSTDIR}/2.4.1

do-install:
	@zcat ${DISTDIR}/docbk241.tar.Z |(cd ${INSTDIR}/2.4.1; pax -r)
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/2.4.1/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/2.4.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/2.4.1/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${MKCATALOG} -q install ${PORTNAME}/2.4.1

.include <bsd.port.mk>
