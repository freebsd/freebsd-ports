# New ports collection makefile for:   knifty
# Date created:        February 22th, 2005
# Whom:                decept
#
# $FreeBSD$
#

PORTNAME=	knifty
PORTVERSION=	0.4.2
CATEGORIES=	x11-themes
MASTER_SITES=	http://kde-look.org/content/files/
DISTNAME=	8841-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	Lightweight KDE window decoration

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lkdeui|-lkdeui ${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-lkdecore|-lkdecore ${PTHREAD_LIBS}|g' \
		${WRKSRC}/client/Makefile.in

.include <bsd.port.mk>
