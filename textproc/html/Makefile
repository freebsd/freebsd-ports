# New ports collection makefile for:	html
# Date created:		Sept 19, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	html
PORTVERSION=	4.01
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
EXTRACT_ONLY=	# empty

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	All W3C published SGML DTDs for HTML

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB=	DTD_NAME=${PORTNAME} XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

INSTDIR=	${PREFIX}/share/sgml/html
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

pre-su-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@zcat ${DISTDIR}/${DISTFILES} |(cd ${INSTDIR}; ${PAX} -r)
	@${CHMOD} ${SHAREMODE} `${FIND} ${INSTDIR} -type f`
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${PORTNAME}/catalog

.include <bsd.port.mk>
