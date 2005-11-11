# New ports collection makefile for:   lipstik
# Date created:                        12th February, 2005
# Whom:                                decept
#
# $FreeBSD$
#

PORTNAME=	lipstik
PORTVERSION=	1.3
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/content/files/
DISTNAME=	18223-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	Modified Plastik KDE style

USE_AUTOTOOLS=	autoheader:259
USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lkdefx|-lkdefx ${PTHREAD_LIBS}|g' \
		${WRKSRC}/style/Makefile.in
post-configure:
	@${REINPLACE_CMD} -e 's|-ljpeg|-ljpeg ${PTHREAD_LIBS}|g' \
		${WRKSRC}/style/config/Makefile

.include <bsd.port.mk>
