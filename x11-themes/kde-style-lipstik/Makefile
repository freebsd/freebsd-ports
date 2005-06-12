# New ports collection makefile for:   lipstik
# Date created:        February 12th, 2005
# Whom:                decept
#
# $FreeBSD$
#

PORTNAME=	lipstik
PORTVERSION=	1.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/content/files/
DISTNAME=	18223-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	Modified Plastik KDE style

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lkdeui|-lkdeui ${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-lkdefx|-lkdefx ${PTHREAD_LIBS}|g' \
		${WRKSRC}/style/Makefile.in

.include <bsd.port.mk>
