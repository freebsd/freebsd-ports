# New ports collection makefile for:   jrefentry
# Date created:                1 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jrefentry
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	docbook

MAINTAINER=	fuyuki@mj.0038.net

RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/catalog:${PORTSDIR}/textproc/docbook-xml \
		${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

NO_BUILD=	yes
PLIST_SUB=	MKCATALOG=${MKCATALOG} CATALOG=${CATALOG}

XMLDIR=		${PREFIX}/share/xml/docbook/${PORTNAME}

MKCATALOG=	${LOCALBASE}/sbin/mkcatalog
CATALOG=	${PREFIX}/share/xml/docbook/catalog

do-install:
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/jrefentry.dtd ${XMLDIR}
	${ECHO_CMD} 'PUBLIC "-//Norman Walsh//DTD JRefEntry V1.1//EN" "jrefentry.dtd"' \
		>${XMLDIR}/catalog

post-install:
	${MKCATALOG} -c ${CATALOG} -q install jrefentry
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/jtest.xml ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}

.include <bsd.port.mk>
