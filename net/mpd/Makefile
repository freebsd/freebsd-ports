# New ports collection makefile for:	mpd
# Date created:				25 Feb 1999
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	mpd
PORTVERSION=	3.18
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	archie
DIST_SUBDIR=	mpd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-link PPP daemon based on netgraph(4) [legacy version]

# lang/mpd
CONFLICTS=	mpd-[^3]*

MAN8=		mpd.8
MANCOMPRESSED=	maybe

USE_OPENSSL=	yes
MAKE_ENV=	COPTS="${COPTS} -I${OPENSSLINC}" LDADD="${LDADD} -L${OPENSSLLIB}"

USE_RC_SUBR=	mpd

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800097
BROKEN=		does not compile
.endif

pre-build:
	@${ECHO}
	@${ECHO} "Use WITH_OPENSSL_PORT=yes if you use OPENSSL from ports"
	@${ECHO}

pre-install:
	@${MKDIR} ${PREFIX}/etc/mpd
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
