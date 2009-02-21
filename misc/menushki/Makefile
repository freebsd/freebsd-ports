# New ports collection makefile for:	menushki
# Date created:				Fri Jul 13 22:59:59 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	menushki
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Menu converter between varieties of Window Managers

DEPRECATED=	unmaintained, does not work with current versions of GCC, needs gcc295 which has been failing to build for months
EXPIRATION_DATE=2009-03-22

USE_XORG=	x11
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GCC=	2.95

PLIST_FILES=	bin/menushki
PORTDOCS=	AUTHORS ChangeLog README TODO

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
