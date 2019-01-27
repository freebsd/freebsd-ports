# Created by: KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdocbook-xml
PORTVERSION=	1.1
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	textproc
MASTER_SITES=	https://www.oasis-open.org/docbook/xml/simple/${PORTVERSION}/
DISTNAME=	docbook-simple-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	"Simplified" DocBook XML DTD

LICENSE=	OASIS
LICENSE_NAME=	OASIS License
LICENSE_TEXT=	License text is available in all files installed by this port
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS+=	xmlcatmgr:textproc/xmlcatmgr

USES=		zip
NO_MTREE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

CATALOG_FILES=	catalog catalog.xml
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}
DTD_NAME=	sdocbook
DTD_VERSION=	${PORTVERSION}
DTD_SUBDIR=	/dtd
DTDDIR=		share/xml/${DTD_NAME}/${DTD_VERSION}${DTD_SUBDIR}
PLIST_SUB+=	DTDDIR=${DTDDIR}
SUB_FILES=	${CATALOG_FILES}
SUB_LIST+=	DTDDIR=${PREFIX}/${DTDDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.css *.dtd *.mod" ${STAGEDIR}${PREFIX}/${DTDDIR}
.for f in ${CATALOG_FILES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/${DTDDIR}
.endfor

.include <bsd.port.mk>
