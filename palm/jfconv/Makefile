# ports collection makefile for:	jconv
# Date created:			14 May 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jconv
PORTVERSION=	2000.05.17
CATEGORIES=	palm databases
MASTER_SITES=	http://www.land-j.com/files/ \
		http://people.FreeBSD.org/~knu/ports/distfiles/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org

ALL_TARGET=	# none

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jconv ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/jconv/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jconv/

.include <bsd.port.mk>
