# New ports collection makefile for:	sysrc
# Date created:				28 December 2011
# Whom:					Devin Teske <dteske@vicor.com>
#
# $FreeBSD$
#

PORTNAME=	sysrc
PORTVERSION=	3.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/

MAINTAINER=	dteske@vicor.com
COMMENT=	Utility to get or set rc.conf(5) values

NO_BUILD=	yes

PLIST_FILES=	sbin/${PORTNAME}
MAN8=		${PORTNAME}.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8/

.include <bsd.port.mk>
