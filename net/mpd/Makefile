# New ports collection makefile for:	mpd
# Date created:				25 Feb 1999
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	mpd
PORTVERSION=	3.18
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	archie
DIST_SUBDIR=	mpd

MAINTAINER=	archie@freebsd.org
COMMENT=	Multi-link PPP daemon based on netgraph(4)

MTREE_FILE=	${FILESDIR}/mpd.mtree
MAN8=		mpd.8
MANCOMPRESSED=	maybe

.if defined(WITH_OPENSSL_PORT)
USE_OPENSSL_PORT=yes
MAKE_ENV=	COPTS=-I${OPENSSLINC} LDADD=-L${OPENSSLLIB} MPD_CONF_DIR="${PREFIX}/etc/mpd"
.else
USE_OPENSSL_BASE=yes
MAKE_ENV=	COPTS=-I${OPENSSLINC} MPD_CONF_DIR="${PREFIX}/etc/mpd"
.endif

pre-build:
	@${ECHO}
	@${ECHO} "Use WITH_OPENSSL_PORT=yes if you use OPENSSL from ports"
	@${ECHO}

post-install:
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/mpd.sh ${PREFIX}/etc/rc.d/mpd.sh.sample

.include <bsd.port.mk>
