# New ports collection makefile for:	octave-forge-base
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

# The reason for this port is because the octave packaging system and the
# FreeBSD packaging system are not very robust.  When it works, it works
# beautifully.  But if something goes wrong, the octave packaging system
# can be left in a rather unusable stat.
# pkg_delete -r octave-forge-base-${PORTVERSION}
# gives the user an opportunity to start with a completely new slate.

PORTNAME=	octave-forge-base
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	#none
DISTFILES=	#none
EXTRACT_ONLY=	#none

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge baseport for all packages

RUN_DEPENDS+=	octave:${PORTSDIR}/math/octave

BROKEN=		incomplete pkg-plist

do-build:
	@${DO_NADA}

do-install:
	${MKDIR} ${LOCALBASE}/share/octave/tarballs
	${MKDIR} ${LOCALBASE}/share/octave/packages
	${MKDIR} ${LOCALBASE}/libexec/octave/packages

.include <bsd.port.mk>
