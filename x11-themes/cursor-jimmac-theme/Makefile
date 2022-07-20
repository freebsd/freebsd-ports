PORTNAME=	cursor-jimmac-theme
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://smyrak.com/freebsd/dists/
DISTNAME=	Jimmac

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Beautiful Jimmac X cursor themes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/Jimmac/cursors
	cd ${WRKSRC}/jimmac/cursors \
		&& ${INSTALL_DATA} * ${STAGEDIR}${PREFIX}/share/icons/Jimmac/cursors

.include <bsd.port.mk>
