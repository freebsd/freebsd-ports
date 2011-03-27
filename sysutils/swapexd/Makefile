# New ports collection makefile for:	swapexd
# Date created:				26 March 2011
# Whom:					Jesse Smith
#
# $FreeBSD$
#

PORTNAME=	swapexd
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://makeapbi.sourceforge.net/${PORTNAME}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A tool for growing and shrinking on-disk swap space

WRKSRC=	${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf

.include <bsd.port.mk>
