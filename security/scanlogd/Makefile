# New ports collection makefile for:	scanlogd
# Date created:				10 May 2004
# Whom:					Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	scanlogd
PORTVERSION=	2.2.5
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://openwall.com/scanlogd/ \
		ftp://ftp.openwall.com/pub/projects/scanlogd/ \
		ftp://rt.fm/pub/scanlogd/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	TCP port scan detection tool

USE_RC_SUBR=	yes

.if defined(WITH_LIBNIDS)
BUILD_DEPENDS+= ${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids
ALL_TARGET=	libnids
.else
ALL_TARGET=	libpcap
.endif
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -c" LD="${CC}"

MAN8=		scanlogd.8
PLIST_FILES=	bin/scanlogd \
		etc/rc.d/scanlogd.sh

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanlogd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scanlogd.8 ${MANPREFIX}/man/man8

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/scanlogd.sh > ${PREFIX}/etc/rc.d/scanlogd.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/scanlogd.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
