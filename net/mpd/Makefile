# New ports collection makefile for:	mpd
# Date created:				25 Feb 1999
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	mpd
PORTVERSION=	3.18
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	archie
DIST_SUBDIR=	mpd

MAINTAINER=	archie@freebsd.org
COMMENT=	Multi-link PPP daemon based on netgraph(4)

MTREE_FILE=	${FILESDIR}/mpd.mtree
MAN8=		mpd.8
MANCOMPRESSED=	maybe

USE_OPENSSL=	yes
USE_RC_SUBR=    yes
MAKE_ENV=	COPTS="${COPTS} -I${OPENSSLINC}" LDADD="${LDADD} -L${OPENSSLLIB}"

.include <bsd.port.pre.mk>

pre-build:
	@${ECHO}
	@${ECHO} "Use WITH_OPENSSL_PORT=yes if you use OPENSSL from ports"
	@${ECHO}

post-install:
	@${SED} -e "s=%%RC_SUBR%%=${RC_SUBR}=" \
		-e "s=%%PREFIX%%=${PREFIX}=" \
		< ${FILESDIR}/mpd.sh > ${WRKSRC}/mpd.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/mpd.sh ${PREFIX}/etc/rc.d/mpd.sh

.include <bsd.port.post.mk>
