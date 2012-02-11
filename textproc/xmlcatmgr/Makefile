# Ports collection makefile for:  xmlcatmgr
# Date created:			  Sat May 24, 2003
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlcatmgr
PORTVERSION=	2.2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	SGML and XML catalog manager

MAN1=		xmlcatmgr.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		DEFAULT_CATALOG_SGML=${CATALOG_PORTS_SGML} \
			DEFAULT_CATALOG_XML=${CATALOG_PORTS_XML}
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif
PKGINSTALL=		${WRKDIR}/pkg-install
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall
SUB_FILES=		pkg-install \
			pkg-deinstall \
			pkg-message
SUB_LIST=		XMLCATMGR=${XMLCATMGR} \
			CATALOG_MASTER_SGML=${CATALOG_MASTER_SGML} \
			CATALOG_MASTER_XML=${CATALOG_MASTER_XML} \
			CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML} \
			CATALOG_PORTS_XML=${CATALOG_PORTS_XML}

XMLCATMGR?=		${PREFIX}/bin/xmlcatmgr
CATALOG_MASTER_SGML?=	${PREFIX}/share/sgml/catalog
CATALOG_PORTS_SGML?=	${PREFIX}/share/sgml/catalog.ports
CATALOG_MASTER_XML?=	${PREFIX}/share/xml/catalog
CATALOG_PORTS_XML?=	${PREFIX}/share/xml/catalog.ports

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
