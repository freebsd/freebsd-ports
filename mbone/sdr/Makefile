# New ports collection makefile for:	sdr
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdr
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	mbone tk82
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/2.9/

MAINTAINER=	fenner@FreeBSD.org
COMMENT=	Multicast Session Directory

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82
BUILD_DEPENDS=	${LOCALBASE}/lib/libuclmmbase.a:${PORTSDIR}/devel/uclmmbase

PLIST_FILES=	bin/sdr
WRKSRC=		${WRKDIR}/sdr/freebsd
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile.freebsd ${WRKSRC}/Makefile.freebsd

.include <bsd.port.mk>
