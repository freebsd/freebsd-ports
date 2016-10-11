# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	sysvbanner
PORTVERSION=	1.0.15
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SysV banner

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	uffejakobsen

ALL_TARGET=	banner

PLIST_FILES=	bin/sysvbanner man/man1/sysvbanner.1.gz

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/banner \
		${STAGEDIR}${PREFIX}/bin/sysvbanner
	${INSTALL_MAN} ${BUILD_WRKSRC}/banner.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/sysvbanner.1

.include <bsd.port.mk>
