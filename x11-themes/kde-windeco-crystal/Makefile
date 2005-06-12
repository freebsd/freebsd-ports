# New ports collection makefile for:   crystal
# Date created:        March 15th, 2005
# Whom:                decept
#
# $FreeBSD$
#

PORTNAME=	crystal
PORTVERSION=	0.9.2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/content/files/
DISTNAME=	13969-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	Transparent KDE window decoration

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDEBASE_VER=3
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lkdeui|-lkdeui ${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-lkdeui|-lkdeui ${PTHREAD_LIBS}|g' \
		${WRKSRC}/client/Makefile.in

.include <bsd.port.mk>
