# ex:ts=8
# Ports collection makefile for:	csv2latex
# Date created:			May 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	csv2latex
PORTVERSION=	0.12.3
PORTEPOCH=	1
CATEGORIES=	textproc converters
MASTER_SITES=	http://ppa.launchpad.net/brouits/ppa/ubuntu/pool/main/c/csv2latex/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Converts a well formed csv file to a LaTeX document

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/csv2latex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
