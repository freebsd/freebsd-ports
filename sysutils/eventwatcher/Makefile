# New ports collection makefile for:   eventwatcher
# Date created:        20 Aug 2004
# Whom:                Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	eventwatcher
PORTVERSION=	0.4.1
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	eventwatcher

MAINTAINER=	lauri@kde.org
COMMENT=	KDE log file/event viewer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
