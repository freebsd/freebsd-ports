# New ports collection makefile for:	bsflite
# Date created:				3 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	bsflite
DISTVERSION=	0.80
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=bsflite

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A lightweight command line AIM client

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsflite ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config-example ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in COPYING ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
