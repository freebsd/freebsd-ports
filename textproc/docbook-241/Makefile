# Created by: nik
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	2.4.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/sgml/2.4.1/
PKGNAMESUFFIX=	241
DISTNAME=	docbk241
EXTRACT_SUFX=	.zip

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	V2.4.1 of the DocBook DTD, designed for technical documentation

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	-s ,^,${DISTNAME}/,

DTDDIR=		${PREFIX}/share/sgml/docbook/2.4.1/dtd
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
