# New ports collection makefile for:	abyssws
# Date created:				26 August 2007
# Whom:					Daniel Voisine
#
# $FreeBSD$
#

PORTNAME=	abyssws
PORTVERSION=	2.4
CATEGORIES=	www
MASTER_SITES=	http://www.aprelium.com/data/
DISTNAME=	abwsx1-freebsd
EXTRACT_SUFX=	.tgz

MAINTAINER=	voisined@wit.edu
COMMENT=	Abyss Web Server is a compact and easy to use web server

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

WRKSRC=		${WRKDIR}/abyssws
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

USE_RC_SUBR=	abyssws.sh

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/lib/abyssws
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${PREFIX}/lib/abyssws -xf -

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
