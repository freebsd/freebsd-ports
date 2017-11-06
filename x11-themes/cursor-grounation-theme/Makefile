# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	cursor-grounation-theme
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	14484-Grounation-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Moshi's Grounation cursors

NO_BUILD=	yes
USES=	tar:bzip2

WRKSRC=		${WRKDIR}/Grounation-${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/grounation/cursors
	${INSTALL_DATA} ${WRKSRC}/Grounation/cursors/* \
		${STAGEDIR}${PREFIX}/share/icons/grounation/cursors

.include <bsd.port.mk>
