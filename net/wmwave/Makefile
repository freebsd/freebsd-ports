# New ports collection makefile for:	wmwave
# Date created:		27 December 2001
# Whom:			Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=       wmwave
PORTVERSION=    0.4
CATEGORIES=     net
MASTER_SITES=   http://www.schuermann.org/~dockapps/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/}
EXTRACT_SUFX=	.tgz

MAINTAINER=     bms@spc.org

MAKEFILE=	${FILESDIR}/Makefile
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XPM=	yes
MAKE_ENV=	MANPREFIX=${MANPREFIX}

MAN1=		wmwave.1
MANCOMPRESSED=	yes

# configure is a no-op for this port.
do-configure:

.include <bsd.port.mk>
