# New ports collection makefile for:	dgd-lpmud
# Date created:		10 November 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	dgd-lpmud
PORTVERSION=	2.4.5
CATEGORIES=	net devel games
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/lpc/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd|}
DISTFILES=	2.4.5-for-1.1.tgz

MAINTAINER=	glewis@FreeBSD.org

NO_PACKAGE=	"depends on DGD, which is NO_CDROM"
RESTRICTED=	"no monetary gain, tarball OK for CDROM"

RUN_DEPENDS=	${PREFIX}/dgd/bin/driver:${PORTSDIR}/net/dgd

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/mud
PLIST_SUB+=	EXTRA:=""

do-build:
	@cd ${WRKDIR}/mud/bin; make

do-install:
	@${TAR} -C ${WRKSRC} -cf - `${GREP} '^[a-z]' ${PLIST} | ${CUT} -f2- -d'/'` \
		| ${TAR} -C ${PREFIX}/dgd -xpf -
	@${INSTALL_DATA} ${WRKSRC}/lpmud-2.4.5/ACCESS.ALLOW \
		${PREFIX}/dgd/lpmud-2.4.5/ACCESS.ALLOW.example
	@${INSTALL_DATA} ${WRKSRC}/lpmud-2.4.5/ACCESS.DENY \
		${PREFIX}/dgd/lpmud-2.4.5/ACCESS.DENY.example
	@${MKDIR} ${PREFIX}/dgd/lpmud-2.4.5/log
	@${MKDIR} ${PREFIX}/dgd/lpmud-2.4.5/open
	@${MKDIR} ${PREFIX}/dgd/lpmud-2.4.5/players/lars/lars
	@${MKDIR} ${PREFIX}/dgd/lpmud-2.4.5/room/post_dir
	@${MKDIR} ${PREFIX}/dgd/tmp

.include <bsd.port.mk>
