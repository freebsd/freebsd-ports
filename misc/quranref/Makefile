# New ports collection makefile for:	quranref
# Date created:				26 July 2000
# Whom:					Kim Scarborough <user@unknown.nu>
#
# $FreeBSD$
#

PORTNAME=	quranref
PORTVERSION=	1.01
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.unknown.nu/ports/

MAINTAINER=	user@unknown.nu
COMMENT=	An interactive Quran (Koran)

BUILD_DEPENDS=	icont:${PORTSDIR}/lang/icon

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.2000 ${DOCSDIR}
.endif

.include <bsd.port.mk>
