# New ports collection makefile for:	sdr
# Version required:			2.9
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	sdr-2.9
CATEGORIES=	mbone tk82
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/2.9/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82
BUILD_DEPENDS=	${LOCALBASE}/lib/libuclmmbase.a:${PORTSDIR}/mbone/uclmmbase

WRKSRC=		${WRKDIR}/sdr/freebsd
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

RESTRICTED=	"Contains DES cryptography."

post-extract:
	@${CP} ${FILESDIR}/Makefile.freebsd ${WRKSRC}/Makefile.freebsd

.include <bsd.port.mk>
