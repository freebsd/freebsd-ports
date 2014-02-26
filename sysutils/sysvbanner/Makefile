# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	sysvbanner
PORTVERSION=	1.0.15
CATEGORIES=	sysutils
MASTER_SITES=	http://github.com/uffejakobsen/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	uffe@uffe.org
COMMENT=	SysV banner

USES=		gmake

ALL_TARGET=	banner

PLIST_FILES=	bin/sysvbanner man/man1/sysvbanner.1.gz

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/banner \
		${STAGEDIR}${PREFIX}/bin/sysvbanner
	${INSTALL_MAN} ${BUILD_WRKSRC}/banner.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/sysvbanner.1

.include <bsd.port.mk>
