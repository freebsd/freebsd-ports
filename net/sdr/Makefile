# New ports collection makefile for:	sdr
# Version required:			2.7
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	sdr-2.7
CATEGORIES=	mbone tk82
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/2.7/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${DISTNAME}/common ${DISTNAME}/sdr

RESTRICTED=	"Contains DES cryptography."

# Makefile.work and configure help to work with the sdr multi-platform
# build structure.
post-extract:
	@${CP} ${FILESDIR}/Makefile.work ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/configure ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/configure

.include <bsd.port.mk>
