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
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/sgml/3.1/
DISTNAME=	docbk31

MAINTAINER=	nik@FreeBSD.org

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_ZIP=	yes
NO_MTREE=	yes
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME} DTD_VERSION=${PORTVERSION} \
		MKCATALOG=${MKCATALOG}

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog
MKCATALOG=	${PREFIX}/sbin/mkcatalog

LATEST_LINK=	docbook-310

pre-install:
	@[ -d ${INSTDIR}/3.1 ] || ${MKDIR} ${INSTDIR}/3.1

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}/3.1
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/3.1/catalog
	@${ECHO_CMD} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/3.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/3.1/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${MKCATALOG} -q install ${PORTNAME}/${PORTVERSION}

.include <bsd.port.mk>
