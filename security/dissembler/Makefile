# Ports collection makefile for:  dissembler
# Date created:			  13 Mar 2005
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dissembler
PORTVERSION=	0.9
CATEGORIES=	security
MASTER_SITES=	http://www.phiral.com/research/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	A tool that polymorphs bytecode to a printable ASCII string

WRKSRC=	${WRKDIR}/${DISTNAME}
PLIST_FILES=bin/${PORTNAME}
PORTDOCS=	${PORTNAME}.txt

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.txt ${DOCSDIR}
.	endif

.include <bsd.port.mk>
