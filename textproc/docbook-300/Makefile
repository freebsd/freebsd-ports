# New ports collection makefile for:	docbook-300
# Version required:	3.0
# Date created:		7 April 1999
# Whom:			nclayton
#
# Based heavily on work by jfieber
#
# $Id: Makefile,v 1.4 1998/06/27 05:19:35 asami Exp $
#

DISTNAME=	docbook-3.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ora.com/pub/davenport/
DISTFILES=	docbk30.tar.Z

MAINTAINER=	nclayton@FreeBSD.ORG

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
	@echo "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/3.0/catalog
	@chmod ${SHAREMODE} ${INSTDIR}/3.0/*
	@/usr/sbin/chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
