# New ports collection makefile for:	xfaces-3.3
# Date created:		11 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
# With some
# modifications from:	Andreas Klemm <andreas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfaces
PORTVERSION=	3.3
CATEGORIES=	mail
# xfaces-sounds.tar.gz only in LOCAL_PORTS
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/xfaces/ \
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS
DISTFILES=	${DISTNAME}.tar.Z xfaces-sounds.tar.gz

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

BUILD_DEPENDS=	${X11BASE}/lib/libaudio.a:${PORTSDIR}/audio/nas
LIB_DEPENDS=	compface.1:${PORTSDIR}/mail/faces

USE_IMAKE=	YES
USE_XPM=	YES
MAN1=		xfaces.1

pre-configure:
	@${LN} -sf ../sounds ${WRKSRC}

pre-install:
	@${MKDIR} ${LOCALBASE}/share/sounds
	@${MKDIR} ${X11BASE}/include/X11/pixmaps

.include <bsd.port.mk>
