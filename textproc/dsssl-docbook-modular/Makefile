# New ports collection makefile for:	DSSSL stylesheets for DocBook
# Date created:		16 March 1998
# Whom:			Jun Kuriyama <kuriyama@opt.phys.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dsssl-docbook-modular
PORTVERSION=	1.78
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	docbook
DISTNAME=	docbook-dsssl-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} docbook-dsssl-doc-${PORTVERSION}${EXTRACT_SUFX}

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
	@${RM} -Rf ${WRKSRC}/docsrc

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${FIND} ${WRKDIR} -name '*~' -exec ${RM} {} \;
	@${FIND} ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

do-install:
	@${CP} -Rp ${WRKSRC}/* ${INSTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	-${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${RELDIR}/catalog
	@${CAT} ${FILESDIR}/install-note

.include <bsd.port.mk>
