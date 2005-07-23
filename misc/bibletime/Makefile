# New ports collection makefile for: bibletime
# Date created:   3 May 2002
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wvengen@stack.nl
COMMENT=	A powerful Bible study application for KDE3

LIB_DEPENDS=	sword.4:${PORTSDIR}/misc/sword

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/bibletime/Makefile.in

.include <bsd.port.mk>
