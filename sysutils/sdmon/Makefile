PORTNAME=	sdmon
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	archimedes.gaviola@gmail.com
COMMENT=	Utility to get SD card health data
WWW=		https://github.com/Ognian/sdmon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Ognian

MAKEFILE=	Makefile.freebsd
ALL_TARGET=
INSTALL_TARGET=

WRKSRC_SUBDIR=	src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdmon ${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/sdmon

.include <bsd.port.mk>
