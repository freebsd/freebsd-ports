# New ports collection makefile for:	DocBook XML DTD
# Date created:		28 March 1999
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	docbook
PKGNAMESUFFIX=	-xml
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/xml/${PORTVERSION}/
DISTNAME=	docbkx412

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_ZIP=	YES
NO_BUILD=	YES
NO_WRKSUBDIR=	YES
PLIST_SUB=	DTD_VERSION=${PORTVERSION} \
		MKCATALOG=${MKCATALOG} CATALOG=${CATALOG}

DOCBOOKDIR=	${PREFIX}/share/xml/${PORTNAME}/${PORTVERSION}
MKCATALOG=	${LOCALBASE}/sbin/mkcatalog
CATALOG=	${PREFIX}/share/xml/catalog

pre-install:
	@[ -d ${DOCBOOKDIR}/ent ] || ${MKDIR} ${DOCBOOKDIR}/ent

do-install:
	for file in `unzip -l ${DISTDIR}/${DISTFILES}|${AWK} '/:[0-9].*[^\/]$$/{print $$4}'`; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${DOCBOOKDIR}/$$file; \
	done

post-install:
	${MKCATALOG} -q -c ${CATALOG} install docbook/${PORTVERSION} docbook.cat

.include <bsd.port.mk>
