# Created by: murray
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	4.1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/sgml/4.1/
DISTNAME=	docbk41

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	V4.1 of the DocBook DTD, designed for technical documentation

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DTDDIR=		share/sgml/docbook/4.1/dtd
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

PKGNAMESUFFIX=	${PKGORIGIN:T:S/docbook-//}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}
	files=$$(${FIND} ${WRKSRC} -type f \! -name '.*'); \
	for i in $${files}; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/${DTDDIR}; \
	done
	${INSTALL_DATA} ${FILESDIR}/catalog ${STAGEDIR}${PREFIX}/${DTDDIR}
	@${ECHO} "CATALOG \"${ISOCAT}\"" >> ${STAGEDIR}${PREFIX}/${DTDDIR}/catalog


.include <bsd.port.mk>
