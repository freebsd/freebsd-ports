# New ports collection makefile for:   xmlcharent
# Date created:                31 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	xmlcharent
PORTVERSION=	0.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	fuyuki@mj.0038.net

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

XMLDIR=		${PREFIX}/share/xml/${PORTNAME}

MKCATALOG=	${LOCALBASE}/sbin/mkcatalog
PLIST_SUB=	MKCATALOG=${MKCATALOG}

do-install:
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ent ${FILESDIR}/catalog ${XMLDIR}

post-install:
	${MKCATALOG} -c ${PREFIX}/share/xml/catalog -q install xmlcharent
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}

.include <bsd.port.mk>
