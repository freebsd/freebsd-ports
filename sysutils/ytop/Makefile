PORTNAME=	ytop
DISTVERSION=	1.0.2
CATEGORIES=	sysutils

MAINTAINER=	vim@vimer.org
COMMENT=	Minimal process monitor for FreeBSD
WWW=		https://github.com/Yeatol/freebsd_ytop

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++23-lang ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	Yeatol
GH_PROJECT=	freebsd_ytop

NO_TEST=	yes
PLIST_FILES=	bin/ytop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ytop ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
