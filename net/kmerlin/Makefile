# New ports collection makefile for:   kmerlin
# Date created:        20 September 2002
# Whom:                Cédric Lamalle
#
# $FreeBSD$
#

PORTNAME=	kmerlin
PORTVERSION=	1.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		cedric@cedric.trix.net

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}

pre-configure:
	cd ${WRKSRC} && ${GMAKE} -f Makefile.cvs

.include <bsd.port.mk>
