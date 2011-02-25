# New ports collection makefile for:	xsmbrowser
# Date Created:				4 Dec 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	xsmbrowser
PORTVERSION=	3.4.0
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://nuxo1.free.fr/logiciel_reseau/visu_reso/ \
		http://mirror.uni-c.dk/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk port of Windows Network Neighborhood

RUN_DEPENDS=	${LOCALBASE}/bin/smbclient:${PORTSDIR}/${SAMBA_PORT} \
		${LOCALBASE}/bin/expectk:${PORTSDIR}/lang/expect

SAMBA_PORT?=	net/samba34

USE_PERL5_BUILD=yes

do-build:
	${PERL} -pi -e s!%%PREFIX%%!${PREFIX}!g ${WRKSRC}/xsmbrowser

do-install:
	${MKDIR} ${PREFIX}/share/xsmbrowser
	${MKDIR} ${PREFIX}/etc/xsmbrowser
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${PREFIX}/share/xsmbrowser
	${INSTALL_SCRIPT} ${WRKSRC}/xsmbrowser ${PREFIX}/bin

.include <bsd.port.mk>
