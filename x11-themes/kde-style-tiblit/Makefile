# New ports collection makefile for:   tiblit
# Date created:        March 13th, 2005
# Whom:                decept
#
# $FreeBSD$
#

PORTNAME=	tiblit
PORTVERSION=	1.2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/content/files/
DISTNAME=	20798-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	KDE style focused on customization

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lkdefx|-lkdefx ${PTHREAD_LIBS}|g' \
		${WRKSRC}/widget-engine/Makefile.in

.include <bsd.port.mk>
