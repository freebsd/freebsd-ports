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
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/sgml/4.0/
DISTNAME=	docbk40

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	V4.0 of the DocBook DTD, designed for technical documentation

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DTDDIR=		share/sgml/docbook/4.0/dtd
PLIST_SUB+=	SGMLCAT_ADD="${SGMLCAT_ADD}" \
		SGMLCAT_RM="${SGMLCAT_RM}"

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
SGMLCAT=	${PREFIX}/share/sgml/catalog.ports
XMLCAT=		${PREFIX}/share/xml/catalog.ports
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

SGMLCAT_ADD=	${XMLCATMGR} -sc ${SGMLCAT} add CATALOG \
		    ${PREFIX}/${DTDDIR}/catalog
SGMLCAT_RM=	${XMLCATMGR} -sc ${SGMLCAT} remove \
		    ${PREFIX}/${DTDDIR}/catalog

LATEST_LINK=	docbook-400

do-install:
	@${MKDIR} ${PREFIX}/${DTDDIR}
	files=$$(${FIND} ${WRKSRC} -type f | ${GREP} -v "${WRKSRC}/\."); \
	for i in $${files}; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${DTDDIR}; \
	done
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${PREFIX}/${DTDDIR}/catalog

post-install:
	-${SGMLCAT_ADD}

.include <bsd.port.mk>
