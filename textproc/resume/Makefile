# New ports collection makefile for:   resume
# Date created:                17 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	resume
PORTVERSION=	1.3.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmlresume
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fuyuki@mj.0038.net

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

NO_BUILD=	yes
PLIST_SUB=	MKCATALOG=${MKCATALOG}

XMLDIR=		${PREFIX}/share/xml/${PORTNAME}
MKCATALOG=	${LOCALBASE}/sbin/mkcatalog

do-install:
	${MKDIR} ${XMLDIR}
.for i in dtd xsl
	${CP} -R ${WRKSRC}/${i} ${XMLDIR}
.endfor

post-install:
	${MKCATALOG} -c ${PREFIX}/share/xml/catalog -q install resume/dtd
	${MKDIR} ${EXAMPLESDIR}
.for i in css examples/*
	${CP} -R ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
