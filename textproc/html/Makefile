# Created by: jfieber
# $FreeBSD$

PORTNAME=	html
PORTVERSION=	4.01
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	All W3C published SGML DTDs for HTML

RUN_DEPENDS=	${XMLCATMGR}:textproc/xmlcatmgr

NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB=	DTD_NAME=${PORTNAME} XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

INSTDIR=	${PREFIX}/share/sgml/html
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

do-install:
	${MKDIR} ${STAGEDIR}${INSTDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "2.0 3.2 4.0 4.01 catalog" ${STAGEDIR}${INSTDIR})

.include <bsd.port.mk>
