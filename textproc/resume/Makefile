# New ports collection makefile for:   resume
# Date created:                17 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	resume
PORTVERSION=	1.4.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmlresume
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fuyuki@hadaly.org

NO_BUILD=	yes

XMLDIR=		${PREFIX}/share/xml/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/share/xml/${PORTNAME}
	${CP} -R ${WRKSRC}/dtd/* ${PREFIX}/share/xml/${PORTNAME}
	${MKDIR} ${PREFIX}/share/xsl/${PORTNAME}
	${CP} -R ${WRKSRC}/xsl/* ${PREFIX}/share/xsl/${PORTNAME}

post-install:
	${MKDIR} ${EXAMPLESDIR}
.for i in css examples/*
	${CP} -R ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
