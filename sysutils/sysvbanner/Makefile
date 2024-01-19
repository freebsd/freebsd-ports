PORTNAME=	sysvbanner
PORTVERSION=	1.0.15
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	d.oriented@gmail.com
COMMENT=	SysV banner
WWW=		https://github.com/uffejakobsen/sysvbanner

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	uffejakobsen

ALL_TARGET=	banner

PLIST_FILES=	bin/sysvbanner share/man/man1/sysvbanner.1.gz

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/banner \
		${STAGEDIR}${PREFIX}/bin/sysvbanner
	${INSTALL_MAN} ${BUILD_WRKSRC}/banner.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/sysvbanner.1

.include <bsd.port.mk>
