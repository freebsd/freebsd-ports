# New ports collection makefile for: 	ciscoconf
# Date created: 			11 September 1998
# Whom: 				jabley@clear.co.nz
#
# $FreeBSD$
#

PORTNAME=	ciscoconf
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	http://www.automagic.org/~jabley/

MAINTAINER=	jabley@automagic.org

BUILD_DEPENDS=	makedepend:${PORTSDIR}/x11/XFree86
ALL_TARGET=	depend all
MAN8=		ciscoconfd.8 ciscoconfr.8

post-patch:

	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	${CAT} ${WRKSRC}/Makefile.old | \
	${SED} -e 's#/usr/local#${PREFIX}#g' | \
	${SED} -e 's#lib/cisco#share/cisco#' \
	>> ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ciscoconfd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ciscoconfr ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ciscoconfd.man ${PREFIX}/man/man8/ciscoconfd.8
	${INSTALL_MAN} ${WRKSRC}/ciscoconfr.man ${PREFIX}/man/man8/ciscoconfr.8

post-install:
	${MKDIR} ${PREFIX}/share/cisco/RCS

.include <bsd.port.mk>
