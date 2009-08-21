# New ports collection makefile for:	scanlogd
# Date created:				10 May 2004
# Whom:					Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	scanlogd
PORTVERSION=	2.2.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://openwall.com/scanlogd/ \
		ftp://ftp.openwall.com/pub/projects/scanlogd/ \
		ftp://rt.fm/pub/scanlogd/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	TCP port scan detection tool

USE_RC_SUBR=	${PORTNAME}

.if defined(WITH_LIBNIDS)
BUILD_DEPENDS+= ${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids
ALL_TARGET=	libnids
.else
ALL_TARGET=	libpcap
.endif
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -c" LD="${CC}"

MAN8=		scanlogd.8
PLIST_FILES=	bin/scanlogd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanlogd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scanlogd.8 ${MANPREFIX}/man/man8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
