# Ports collection makefile for:  siphon
# Date created:			  6 May 2000
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	siphon
PORTVERSION=	0.666
CATEGORIES=	security
MASTER_SITES=	http://www.subterrain.net/projects/siphon/
DISTFILES=	siphon-v.666.tar.gz siphon-report.pl
EXTRACT_ONLY=	siphon-v.666.tar.gz

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/siphon-v.666

do-install:
	${MKDIR} ${PREFIX}/share/siphon
	${INSTALL_PROGRAM} ${WRKSRC}/siphon ${PREFIX}/bin
	${INSTALL_SCRIPT} ${DISTDIR}/siphon-report.pl ${PREFIX}/bin/siphon-report
	${INSTALL_DATA} ${WRKSRC}/osprints.conf ${PREFIX}/share/siphon

.include <bsd.port.mk>
