# Created by: Alexander Panyushkin <vsityz@gmail.com>
# $FreeBSD$

PORTNAME=	hans
DISTVERSION=	1.0
CATEGORIES=	net security
MASTER_SITES=	SF/hanstunnel/source

MAINTAINER=	vsityz@gmail.com
COMMENT=	Hans makes it possible to tunnel IPv4 through ICMP

LICENSE=	FPL GPLv3+
LICENSE_COMB=	multi
LICENSE_NAME_FPL=Freeware Public License
LICENSE_FILE_FPL=${WRKSRC}/src/sha1_license.txt
LICENSE_PERMS_FPL=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		dos2unix
DOS2UNIX_FILES=	${LICENSE_FILE_FPL}
MAKE_ARGS=	GCC="${CC}" GPP="${CXX}" \
		CFLAGS="${CFLAGS} -c" LDFLAGS="${LDFLAGS}"
PLIST_FILES=	bin/hans
TARGET_ORDER_OVERRIDE=	040:dos2unix # Fix formatting for 050:ask-license
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hans ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
