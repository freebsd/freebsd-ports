# New ports collection makefile for:	docbook-410
# Date created:		26 June 2000
# Whom:			murray
#
# Based on nik's docbook-310 port
#
# $FreeBSD$
#

PORTNAME=	docbook
PORTVERSION=	4.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/sgml/4.1/
DISTNAME=	docbk41
EXTRACT_ONLY=	# empty

MAINTAINER=	murray@freebsd.org

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_ZIP=	yes
NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME} DTD_VERSION=${PORTVERSION} \
		MKCATALOG=${MKCATALOG}

INSTDIR=	${PREFIX}/share/sgml/docbook
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog
MKCATALOG=	${PREFIX}/sbin/mkcatalog

LATEST_LINK=	docbook-410

pre-install:
	@[ -d ${INSTDIR}/4.1 ] || ${MKDIR} ${INSTDIR}/4.1

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}/4.1
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/4.1/catalog
	@${ECHO_CMD} "CATALOG \"${ISOCAT}\"" >> ${INSTDIR}/4.1/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/4.1/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${MKCATALOG} -q install ${PORTNAME}/${PORTVERSION}

.include <bsd.port.mk>
