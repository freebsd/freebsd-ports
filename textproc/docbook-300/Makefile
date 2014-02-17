# Created by: nik
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	3.0
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/sgml/${PORTVERSION}/
PKGNAMESUFFIX=	300
DISTNAME=	docbk30
EXTRACT_SUFX=	.zip

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	V3.0 of the DocBook DTD, designed for technical documentation

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	-s ,^,${DISTNAME}/,

DTDDIR=		${PREFIX}/share/sgml/docbook/3.0/dtd
PLIST_SUB+=	XMLCATMGR=${XMLCATMGR} SGMLCAT=${SGMLCAT} \
		DTDDIR=${DTDDIR:S/${PREFIX}\///}

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
SGMLCAT=	${PREFIX}/share/sgml/catalog.ports
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog

SUB_FILES=	catalog

do-install:
	@${MKDIR} ${STAGEDIR}${DTDDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DTDDIR}
	${INSTALL_DATA} ${WRKDIR}/catalog ${STAGEDIR}${DTDDIR}

.include <bsd.port.mk>
