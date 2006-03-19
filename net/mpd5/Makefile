# New ports collection makefile for:	mpd
# Date created:				20 Sep 2005
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	mpd4
PORTVERSION=	4.0b4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	glebius
DIST_SUBDIR=	mpd4

MAINTAINER=	glebius@freebsd.org
COMMENT=	Multi-link PPP daemon based on netgraph(4) [development version]

LIB_DEPENDS=	pdel.0:${PORTSDIR}/devel/libpdel

MTREE_FILE=	${FILESDIR}/mpd4.mtree
MAN8=		mpd4.8
MANCOMPRESSED=	maybe

USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD 4.x; use net/mpd instead
.endif

post-install:
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/mpd4.sh ${PREFIX}/etc/rc.d/mpd4.sh.sample

.include <bsd.port.post.mk>
