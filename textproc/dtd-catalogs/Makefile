# Created by: shige
# $FreeBSD$

PORTNAME=	dtd-catalogs
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGML DTDs catalogs

RUN_DEPENDS=	${ISO8879_CAT}:${PORTSDIR}/textproc/iso8879 \
		${ISO12083_CAT}:${PORTSDIR}/textproc/iso12083 \
		${HTML_CAT}:${PORTSDIR}/textproc/html \
		${LINUXDOC_CAT}:${PORTSDIR}/textproc/linuxdoc

NO_BUILD=	yes

# The following catalogs are listed in catalog-list-file actually.
ISO8879_CAT=	${LOCALBASE}/share/sgml/iso8879/catalog
ISO12083_CAT=	${LOCALBASE}/share/sgml/iso12083/catalog
HTML_CAT=	${LOCALBASE}/share/sgml/html/catalog
LINUXDOC_CAT=	${LOCALBASE}/share/sgml/linuxdoc/catalog

NO_STAGE=	yes
do-install:
	@${DO_NADA}

.include <bsd.port.mk>
