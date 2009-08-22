# New ports collection makefile for:	DSSSL stylesheets for DocBook
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dsssl-docbook-modular
PORTVERSION=	1.79
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/docbook-dsssl/${PORTVERSION}
DISTNAME=	docbook-dsssl-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} docbook-dsssl-doc-${PORTVERSION}${EXTRACT_SUFX}

PATCH_SITES=	http://dist.bsdlab.org/
PATCHFILES=	docbook-dsssl-mn-20070525.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	DSSSL stylesheets for the DocBook DTD by Norman Walsh

BUILD_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_MTREE=	yes

RELDIR=		docbook/dsssl/modular
INSTDIR=	${PREFIX}/share/sgml/${RELDIR}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
PLIST_SUB=	XMLCATMGR=${XMLCATMGR} DTDDIR=${RELDIR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

do-build:
	${RM} -Rf ${WRKSRC}/docsrc

pre-su-install:
	${MKDIR} ${INSTDIR}
	${FIND} ${WRKDIR} -name '*.orig' -exec ${RM} {} \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}

do-install:
	@cd ${WRKSRC} && ${TAR} cpf - . | (cd ${INSTDIR} && ${TAR} xpf -)

post-install:
	-${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${RELDIR}/catalog
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
