# New ports collection makefile for:   kcube
# Date created:        05 January 2004
# Whom:                Michael Ranner
#
# $FreeBSD$
#

PORTNAME=	kcube
PORTVERSION=	0.61
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.tuxed.de/kcube/download/

MAINTAINER=	mranner@inode.at
COMMENT=	Another cpu load kicker applet for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
