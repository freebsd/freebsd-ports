# New ports collection makefile for:	quranref
# Date created:				26 July 2000
# Whom:					Kim Scarborough <user@unknown.nu>
#
# $FreeBSD$
#

PORTNAME=	quranref
PORTVERSION=	1.01
CATEGORIES=	misc
MASTER_SITES=	http://www.unknown.nu/ports/

MAINTAINER=	user@unknown.nu
COMMENT=	An interactive Quran (Koran)

BUILD_DEPENDS=	icont:${PORTSDIR}/lang/icon

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/quranref
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/quranref
	${INSTALL_DATA} ${WRKSRC}/README.2000 ${PREFIX}/share/doc/quranref
.endif

.include <bsd.port.mk>
