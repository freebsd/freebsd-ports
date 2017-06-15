# Created by: jfieber
# $FreeBSD$

PORTNAME=	linuxdoc
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://dist.bsdlab.org/ \
		http://fallout.campusview.indiana.edu/ports/distfiles/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	The Linuxdoc SGML DTD

RUN_DEPENDS=	${ISOCAT}:textproc/iso8879 \
		xmlcatmgr:textproc/xmlcatmgr

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/linuxdoc
ISOCAT=		${LOCALBASE}/share/sgml/iso8879/catalog

do-install:
	${MKDIR} ${STAGEDIR}${INSTDIR}
	zcat ${DISTDIR}/${DISTFILES} |(cd ${STAGEDIR}${INSTDIR}; ${PAX} -r)
	${CHMOD} ${SHAREMODE} ${STAGEDIR}${INSTDIR}/*

.include <bsd.port.mk>
