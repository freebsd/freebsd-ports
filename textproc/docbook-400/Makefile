# New ports collection makefile for:	docbook-400
# Date created:		4 April 2000
# Whom:			asmodai
#
# Based on nik's docbook-310 port
#
# $FreeBSD$
#

PORTNAME=	docbook
PORTVERSION=	4.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/sgml/4.0/
DISTNAME=	docbk40

MAINTAINER=	asmodai@FreeBSD.org

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

pre-install:
	@[ -d ${INSTDIR}/4.0 ] || ${MKDIR} ${INSTDIR}/4.0

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}/4.0
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/4.0/catalog
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/4.0/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.0/*
	@${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

post-install:
	@${MKCATALOG} -q install ${PORTNAME}/${PORTVERSION}

.include <bsd.port.mk>
