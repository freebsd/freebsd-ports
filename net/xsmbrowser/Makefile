# New ports collection makefile for:	xsmbrowser
# Date Created:				4 Dec 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	xsmbrowser
PORTVERSION=	3.2
CATEGORIES=	net
MASTER_SITES=	http://www2.iastate.edu/~chadspen/

MAINTAINER=	roman@xpert.com

RUN_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/net/samba \
		${LOCALBASE}/bin/expectk:${PORTSDIR}/lang/expect

RESTRICTED=	"Commercial software"

do-build:
	${PERL} -pi -e s!/etc!${PREFIX}/etc!g ${WRKSRC}/${PORTNAME}
	${PERL} -pi -e 's!"Image Path = pixmaps"!"Image Path = ${PREFIX}/share/${PORTNAME}"!' ${WRKSRC}/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${PREFIX}/share/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
