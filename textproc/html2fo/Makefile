# ex:ts=8
# New ports collection makefile for:	html2fo
# Date created:			Jul 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	html2fo
PORTVERSION=	0.4.2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML to xsl:fo converter

PLIST_FILES=	bin/html2fo
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2fo ${PREFIX}/bin

.include <bsd.port.mk>
