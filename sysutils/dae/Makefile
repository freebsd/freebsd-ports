# New ports collection makefile for:	dae
# Date created:				11 March 2009
# Whom:					Dylan Bridgman
#
# $FreeBSD$
#

PORTNAME=	dae
PORTVERSION=	0.9
CATEGORIES=	sysutils
MASTER_SITES=	#empty
DISTFILES=	#none

MAINTAINER=	light@ether.org.za
COMMENT=	List and control system daemon

MAN1=		dae.1

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/dae

do-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/dae.sh ${PREFIX}/sbin/dae
	@${INSTALL_MAN} ${FILESDIR}/dae.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
