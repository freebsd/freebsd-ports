# ports collection makefile for:	jfconv
# Date created:			14 May 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jfconv
PORTVERSION=	2000.05.17
CATEGORIES=	palm databases
MASTER_SITES=	http://www.land-j.com/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	jconv
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org

ALL_TARGET=	# none

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jconv ${PREFIX}/bin/jfconv
	${MKDIR} ${PREFIX}/share/doc/jfconv/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jfconv/

.include <bsd.port.mk>
