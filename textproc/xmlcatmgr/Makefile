# Ports collection makefile for:  xmlcatmgr
# Date created:			  Sat May 24, 2003
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlcatmgr
PORTVERSION=	2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	SGML and XML catalog manager

MAN1=		xmlcatmgr.1

HAS_CONFIGURE=	yes

CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=		-D \
			-p ${PREFIX} \
			-d ${DOCSDIR} \
			-c ${CATALOG_PORTS_XML} \
			-C ${CATALOG_PORTS_SGML}
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	-n doc
.endif
CONFIGURE_ENV=		SED="${SED}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_DIR="${INSTALL_DATA_DIR}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			NOPORTDOCS="${NOPORTDOCS}"

BUILD_WRKSRC=		${WRKSRC}/work
INSTALL_WRKSRC=		${WRKSRC}/work

COMMONVARS=		${WRKDIR}/commonvars.sh
XMLCATMGR?=		${PREFIX}/bin/xmlcatmgr
CATALOG_MASTER_SGML?=	${PREFIX}/share/sgml/catalog
CATALOG_PORTS_SGML?=	${PREFIX}/share/sgml/catalog.ports
CATALOG_MASTER_XML?=	${PREFIX}/share/xml/catalog
CATALOG_PORTS_XML?=	${PREFIX}/share/xml/catalog.ports

PKGINSTALL=		${WRKDIR}/pkg-install.sh
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall.sh

post-build:
	${TOUCH} ${COMMONVARS}
	${ECHO} '#!/bin/sh' >> ${COMMONVARS}
	${ECHO} 'PATH=$${PATH}:/bin:/usr/bin:${LOCALBASE}/bin:${X11BASE}/bin' >> ${COMMONVARS}
	${ECHO} 'export PATH;' >> ${COMMONVARS}
.for V in XMLCATMGR CATALOG_MASTER_SGML CATALOG_MASTER_XML CATALOG_PORTS_SGML CATALOG_PORTS_XML
	${ECHO} '${V}=${${V}}' >> ${COMMONVARS}
.endfor
	${CAT} ${COMMONVARS} ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CAT} ${COMMONVARS} ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	${CHMOD} 0555 ${PKGINSTALL} ${PKGDEINSTALL}

post-install:
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
