# Created by: jabley@clear.co.nz
# $FreeBSD$

PORTNAME=	ciscoconf
PORTVERSION=	1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	ISC/ciscoconf/ \
		http://software.automagic.org/ciscoconf/

MAINTAINER=	jabley@automagic.org
COMMENT=	Fetches configuration from Cisco routers and stores them under RCS

BUILD_DEPENDS=	makedepend:devel/makedepend

ALL_TARGET=	depend all

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	${CAT} ${WRKSRC}/Makefile.old | \
	${SED} -e 's#/usr/local#${PREFIX}#g' | \
	${SED} -e 's#lib/cisco#share/cisco#' \
	>> ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ciscoconfd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ciscoconfr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ciscoconfd.man \
		${STAGEDIR}${MANPREFIX}/man/man8/ciscoconfd.8
	${INSTALL_MAN} ${WRKSRC}/ciscoconfr.man \
		${STAGEDIR}${MANPREFIX}/man/man8/ciscoconfr.8
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/cisco/RCS

.include <bsd.port.mk>
