# Created by: KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdocbook-xml
PORTVERSION=	1.1
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/simple/${PORTVERSION}/
DISTNAME=	docbook-simple-${PORTVERSION}

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	"Simplified" DocBook XML DTD

RUN_DEPENDS+=	${LOCALBASE}/${XMLCATMGR}:textproc/xmlcatmgr

USES=		zip
NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

XMLCATMGR=	bin/xmlcatmgr
XMLCAT=		share/xml/catalog.ports
SGMLCAT=	share/sgml/catalog.ports
CATALOG_FILES=	catalog catalog.xml
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}
DTD_NAME=	sdocbook
DTD_VERSION=	${PORTVERSION}
DTD_SUBDIR=	/dtd
DTDDIR=		share/xml/${DTD_NAME}/${DTD_VERSION}${DTD_SUBDIR}
PLIST_SUB+=	XMLCATMGR=${XMLCATMGR} SGMLCAT=${SGMLCAT} XMLCAT=${XMLCAT} \
		DTDDIR=${DTDDIR}
SUB_FILES=	${CATALOG_FILES}
SUB_LIST+=	DTDDIR=${PREFIX}/${DTDDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.css *.dtd *.mod" ${STAGEDIR}${PREFIX}/${DTDDIR}
.for f in ${CATALOG_FILES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/${DTDDIR}
.endfor
	@${ECHO_CMD} "@unexec rmdir %D/share/xml/${DTD_NAME} 2>/dev/null || :" >> ${TMPPLIST}

.include <bsd.port.mk>
