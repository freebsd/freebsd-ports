# New ports collection makefile for:	xsmbrowser
# Date Created:				4 Dec 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	xsmbrowser
PORTVERSION=	3.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.public.iastate.edu/~chadspen/

MAINTAINER=	ports@oven.org
COMMENT=	Tcl/Tk port of Windows' Network Neighborhood

RUN_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/net/samba \
		${LOCALBASE}/bin/expectk:${PORTSDIR}/lang/expect

USE_PERL5_BUILD=yes

do-build:
	${PERL} -pi -e s!%%PREFIX%%!${PREFIX}!g ${WRKSRC}/xsmbrowser

do-install:
	${MKDIR} ${PREFIX}/share/xsmbrowser
	${MKDIR} ${PREFIX}/etc/xsmbrowser
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${PREFIX}/share/xsmbrowser
	${INSTALL_SCRIPT} ${WRKSRC}/xsmbrowser ${PREFIX}/bin

.include <bsd.port.mk>
