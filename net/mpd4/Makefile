# New ports collection makefile for:	mpd
# Date created:				20 Sep 2005
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	mpd4
PORTVERSION=	4.0r1
DISTVERSION=	4.0rc1
CATEGORIES=	net
MASTER_SITES=	LOCAL/glebius
DIST_SUBDIR=	mpd4

MAINTAINER=	mav@alkar.net
COMMENT=	Multi-link PPP daemon based on netgraph(4) [development version]

LIB_DEPENDS=	pdel.0:${PORTSDIR}/devel/libpdel

MTREE_FILE=	${FILESDIR}/mpd4.mtree
MAN8=		mpd4.8
MANCOMPRESSED=	maybe
USE_RC_SUBR=	mpd4.sh
HTMLNUM!=	jot 62 1
CONFSUF=	conf links secret script
PORTDOCS=	${HTMLNUM:S/^/mpd/:S/$/.html/} mpd.html mpd.ps README	\
		mpd_toc.html
PLIST_DIRS=	etc/mpd4
PLIST_FILES=	${CONFSUF:S/^/etc\/mpd4\/mpd./:S/$/.sample/} sbin/mpd4

USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD 4.x; use net/mpd instead
.endif

.include <bsd.port.post.mk>
