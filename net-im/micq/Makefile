# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	micq
PORTVERSION=	0.4.6.1
CATEGORIES=	net
MASTER_SITES=   http://micq.ukeer.de/source/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/1/p1/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@freebsd.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1/-p1/}/src

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
		${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/micq
		${INSTALL_DATA} ${WRKSRC}/../CHANGELOG ${PREFIX}/share/doc/micq
.endif

.include <bsd.port.mk>
