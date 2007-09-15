# New ports collection makefile for:	abyssws
# Date created:				26 August 2007
# Whom:					Daniel Voisine <voisined@wit.edu>
#
# $FreeBSD$
#

PORTNAME=	abyssws
PORTVERSION=	2.5
CATEGORIES=	www
MASTER_SITES=	http://www.aprelium.com/data/
DISTNAME=	abwsx1-freebsd
EXTRACT_SUFX=	.tgz

MAINTAINER=	voisined@wit.edu
COMMENT=	Abyss Web Server is a compact and easy to use web server

LIB_DEPENDS=	c.6:${PORTSDIR}/misc/compat6x

WRKSRC=		${WRKDIR}/abyssws
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

USE_RC_SUBR=	abyssws.sh

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	@${INSTALL} -d ${PREFIX}/lib/abyssws
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${PREFIX}/lib/abyssws -xf -
	@ ${CHOWN} -R abyssws:abyssws ${PREFIX}/lib/abyssws/
	@${ECHO_CMD} '@exec ${CHOWN} -R abyssws:abyssws \
		${PREFIX}/lib/abyssws' >> ${TMPPLIST}

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
