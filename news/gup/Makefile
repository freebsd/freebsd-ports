# New ports collection makefile for:	gup
# Version required:	0.4
# Date created:		22 November 1998
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

DISTNAME=	gup-0.4
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.isc.org/isc/inn/unoff-contrib/

MAINTAINER=	dsh@vlink.ru

WRKSRC=		${WRKDIR}/gup

MAN1=		gup.1

do-configure:
	@${CP} ${FILESDIR}/freebsd ${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gup ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/gup.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
