# New ports collection makefile for:    gnut
# Date created:         19 April 2000
# Whom:                 kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnut
PORTVERSION=	0.3.24
CATEGORIES=	net audio
MASTER_SITES=	http://www.umr.edu/~jjp/

MAINTAINER=	kris@FreeBSD.org

USE_AUTOCONF=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnut ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gnut
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gnut
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${PREFIX}/share/doc/gnut
.endif
	${MKDIR} ${PREFIX}/share/gnut
	${INSTALL_DATA} ${WRKSRC}/gnutrc.sample ${PREFIX}/share/gnut

.include <bsd.port.mk>
