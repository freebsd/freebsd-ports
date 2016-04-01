# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	website
PORTVERSION=	2.6.0
CATEGORIES=	textproc www
MASTER_SITES=	SF/docbook/${PORTNAME}/${PORTVERSION}
DISTNAME=	docbook-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doctype and stylesheets for making websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl

NO_ARCH=	yes
NO_BUILD=	yes

USES=		tar:bzip2

SUB_FILES=	pkg-deinstall pkg-install
SUB_LIST=	XMLCATMGR="${XMLCATMGR}" \
		CATALOG_PORTS_XML="${CATALOG_PORTS}" \
		INSTDIR="${INSTDIR}"

OPTIONS_DEFINE=	EXAMPLES

XMLDIR=		${LOCALBASE}/share/xml
INSTDIR=	share/xsl/website
PINSTDIR=	${PREFIX}/${INSTDIR}
COPYDIRS=	extensions schema xsl

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS=	${XMLDIR}/catalog.ports

do-install:
	@${MKDIR} ${STAGEDIR}${PINSTDIR}
.for i in VERSION catalog
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${PINSTDIR})
.endfor
.for i in ${COPYDIRS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${PINSTDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
