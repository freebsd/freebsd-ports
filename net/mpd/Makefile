# New ports collection makefile for:	mpd
# Date created:				25 Feb 1999
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	mpd
PORTVERSION=	3.17
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	archie

MAINTAINER=	archie@freebsd.org
COMMENT=	Multi-link PPP daemon based on netgraph(4)

MTREE_FILE=	${FILESDIR}/mpd.mtree
MAN8=		mpd.8
MANCOMPRESSED=	maybe

USE_OPENSSL=	yes
MAKE_ENV=	COPTS=-I${OPENSSLINC} LDADD=-L${OPENSSLLIB}

post-install:
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/mpd.sh ${PREFIX}/etc/rc.d/mpd.sh.sample

.include <bsd.port.mk>
