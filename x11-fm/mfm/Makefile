# New ports collection makefile for:	mfm
# Version required:			1.2
# Date created:				12 Jan 2000
# Whom:					Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

DISTNAME=	mfm-1.2
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.core-coutainville.org/mfm/archive/SOURCES/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	mtools:${PORTSDIR}/emulators/mtools

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
USE_GMAKE=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mfm ${PREFIX}/bin

.include <bsd.port.mk>
