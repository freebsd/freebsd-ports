# New ports collection makefile for:	wmtz
# Date created:			24 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmtz
PORTVERSION=	0.7
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://www.geocities.com/jl1n/wmtz/ \
		http://soupnazi.org/FreeBSD/ports/distfiles/

MAINTAINER=	jim@FreeBSD.org

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/wmtz
USE_X_PREFIX=	yes
USE_XPM=	yes

post-install:
	@${ECHO} "===>   Installing wmtzrc.default in ${PREFIX}/etc."
	@${ECHO} "===>   Copy it to ~/.wmtzrc or ${PREFIX}/etc/wmtzrc and modify it."
	@${INSTALL_DATA} ${WRKSRC}/wmtzrc ${PREFIX}/etc/wmtzrc.default
	@${ECHO} "===>   Run wmtz --help for usage instructions"

.include <bsd.port.mk>
