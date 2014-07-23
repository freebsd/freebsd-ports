# Created by: Roman Bogorodskiy
# $FreeBSD$

PORTNAME=	scanlogd
PORTVERSION=	2.2.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://openwall.com/scanlogd/ \
		ftp://ftp.openwall.com/pub/projects/scanlogd/ \
		ftp://rt.fm/pub/scanlogd/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	TCP port scan detection tool

USE_RC_SUBR=	${PORTNAME}

.if defined(WITH_LIBNIDS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids
ALL_TARGET=	libnids
.else
ALL_TARGET=	libpcap
.endif

USERS=		scanlogd
GROUPS=		scanlogd
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -c" LD="${CC}"

PLIST_FILES=	bin/scanlogd man/man8/scanlogd.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanlogd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scanlogd.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
