# New ports collection makefile for:   dialog
# Date created:        22 November 2002
# Whom:                vitale
#
# $FreeBSD$
#

PORTNAME=		dialog
PORTVERSION=		0.9b
PORTREVISION=		20030308
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/d/${PORTNAME}
DISTNAME=		${PORTNAME}_${PORTVERSION}-${PORTREVISION}.orig

MAINTAINER=		ferruccio.vitale@tin.it
COMMENT=		Utility to create curses-based menu in shell script

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}-${PORTREVISION}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-catgets
MAKEFILE=		makefile
MAN1=			dialog.1
MANCOMPRESSED=		no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dialog ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libdialog.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/dialog.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

