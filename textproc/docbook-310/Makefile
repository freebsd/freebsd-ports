# New ports collection makefile for:	docbook-310
# Version required:	3.0
# Date created:		7 April 1999
# Whom:			nclayton
#
# Based heavily on work by jfieber
#
# $Id: Makefile,v 1.1.1.1 1999/04/14 22:30:42 nik Exp $
#

DISTNAME=	docbk31
PKGNAME=	docbook-3.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/docbook/3.1/
EXTRACT_SUFX=	.zip

MAINTAINER=	nclayton@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

pre-install:
	@[ -d ${INSTDIR}/3.1 ] || ${MKDIR} ${INSTDIR}/3.1

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}/3.1
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/3.1/catalog
	@echo "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/3.1/catalog
	@chmod ${SHAREMODE} ${INSTDIR}/3.1/*
	@/usr/sbin/chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
