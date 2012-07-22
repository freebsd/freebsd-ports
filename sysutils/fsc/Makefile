# New ports collection makefile for:	FreeBSD Services Control
# Date created:				07 May 2012
# Whom:					Tom Rhodes <trhodes@FreeBSD.org>
#
# $Id: Makefile 1969 2012-06-04 20:00:10Z bsdtrhodes $
# $FreeBSD$
#

PORTNAME=	fsc
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	trhodes

MAINTAINER=	trhodes@FreeBSD.org
COMMENT=	The FreeBSD Services Control family of utilties.

WRKSRC=		${WRKDIR}/fsc

PLIST_FILES=	bin/fscadm \
		sbin/fscd \
		etc/rc.d/fscd \
		man/man5/fscd.conf.5.gz \
		man/man8/fscadm.8.gz \
		man/man8/fscd.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/rc.d/fscd
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/fscd/fscd.8 ${WRKSRC}/fscd/fscd.c \
		${WRKSRC}/fscd/fscd.conf.5 ${WRKSRC}/fscadm/fscadm.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fscadm/fscadm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fscd/fscd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/fscd ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/fscd/fscd.conf.5.gz ${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/fscd/fscd.8.gz ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/fscadm/fscadm.8.gz ${PREFIX}/man/man8

.include <bsd.port.mk>
