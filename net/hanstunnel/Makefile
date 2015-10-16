# Created by: Alexander Panyushkin <vsityz@gmail.com>
# $FreeBSD$

PORTNAME=	hans
PORTVERSION=	0.4.4
CATEGORIES=	net security
MASTER_SITES=	SF/hanstunnel/source

MAINTAINER=	vsityz@gmail.com
COMMENT=	Hans makes it possible to tunnel IPv4 through ICMP

LICENSE=	FPL GPLv3 # or any later version
LICENSE_COMB=	multi
LICENSE_NAME_FPL=Freeware Public License
LICENSE_FILE_FPL=${WRKSRC}/src/sha1_license.txt
LICENSE_PERMS_FPL=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		dos2unix
DOS2UNIX_FILES=	${LICENSE_FILE_FPL}
MAKE_ARGS=	GCC="${CC}" GPP="${CXX}" \
		CFLAGS="${CFLAGS} -c" LDFLAGS="${LDFLAGS}" \
		TUN_DEV_FILE="src/tun_dev_freebsd.c"
PLIST_FILES=	bin/hans

MAKE_JOBS_UNSAFE=	yes

# Remove CRs before ask-license to fix formatting in dialog(1)
post-extract:	dos2unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hans ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
