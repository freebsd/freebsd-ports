# New ports collection makefile for:	kiltdown
# Date Created:				16 Jun 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	kiltdown
PORTVERSION=	0.8.045
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kiltdown

MAINTAINER=	dinoex@FreeBSD.org

LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3

USE_X_PREFIX=	yes
USE_QT_VER=	2
USE_GMAKE=	yes
MY_CONFIGURE_ARGS=	-release
MY_CONFIGURE_ARGS+=	-qtinc /usr/X11R6/include/qt2 -qtlib /usr/X11R6/lib
MY_CONFIGURE_ARGS+=	-dbinc /usr/local/include/db3 -dblib /usr/local/lib
BUILD_ENV+=		PATH=${PATH}:${X11BASE}/bin

do-configure:
	(cd ${CONFIGURE_WRKSRC} && \
		./${CONFIGURE_SCRIPT} ${MY_CONFIGURE_ARGS} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kiltdown/kiltdown ${PREFIX}/bin/

.include <bsd.port.mk>

