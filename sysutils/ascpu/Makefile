# New ports collection makefile for:	ascpu
# Version required:	1.6
# Date created:         18 February 1999
# Whom:                 Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

DISTNAME=	ascpu-1.6
CATEGORIES=	sysutils afterstep
MASTER_SITES=	http://bewoner.dma.be/Albert/software/ \
		http://www.tigr.net/afterstep/as-apps/download/ascpu/	\
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/

MAINTAINER=	dima@Chg.RU

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-xpm

MAN1=		ascpu.1

do-install:
	@ ${INSTALL_MAN} ${WRKSRC}/ascpu.man ${PREFIX}/man/man1/ascpu.1
	@ ${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g kmem -m 2755 ${WRKSRC}/ascpu ${PREFIX}/bin

.include <bsd.port.mk>
