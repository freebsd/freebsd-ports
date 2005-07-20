# New ports collection makefile for:	mime-support
# Date created:		7 March 2003
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	mime-support
PORTVERSION=	3.34.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION:C/(.*)\.([^.])/\1-\2/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	MIME Media Types list

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
PLIST_FILES=	bin/run-mailcap etc/mime.types
MAN1=		run-mailcap.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-mailcap ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mime.types ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/run-mailcap.man ${MANPREFIX}/man/man1/run-mailcap.1

.include <bsd.port.mk>
