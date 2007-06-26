# New ports collection makefile for:	mpd
# Date created:				20 Sep 2005
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	mpd
DISTVERSION=	4.2
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	mpd
DIST_SUBDIR=	mpd4

MAINTAINER=	mav@alkar.net
COMMENT=	Multi-link PPP daemon based on netgraph(4)

LIB_DEPENDS=	pdel.0:${PORTSDIR}/devel/libpdel

LATEST_LINK=    mpd4

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700041
BUILD_DEPENDS=	/usr/local/include/netgraph/ng_car.h:${PORTSDIR}/net/ng_car
RUN_DEPENDS=	${KMODDIR}/ng_car.ko:${PORTSDIR}/net/ng_car
.endif

MTREE_FILE=	${FILESDIR}/mpd4.mtree
MAN8=		mpd4.8
MANCOMPRESSED=	maybe
USE_RC_SUBR=	mpd4.sh
HTMLNUM!=	jot 67 1
CONFSUF=	conf links secret script
DOCSDIR=	${TARGETDIR}/share/doc/mpd4
PORTDOCS=	${HTMLNUM:S/^/mpd/:S/$/.html/} mpd.html mpd.ps README	\
		mpd_toc.html
PLIST_DIRS=	etc/mpd4
PLIST_FILES=	${CONFSUF:S/^/etc\/mpd4\/mpd./:S/$/.sample/} sbin/mpd4

USE_OPENSSL=	yes

.include <bsd.port.post.mk>
