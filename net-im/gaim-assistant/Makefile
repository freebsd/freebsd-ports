# New ports collection makefile for:   gaim-assistant
# Date created:                                10 Dec 2005
# Whom:                                        Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$

PORTNAME=	gaim-assistant
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	MrL0Lz@gmail.com
COMMENT=	Plugin that forwards messages to a different screen name

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GCC=	3.4+

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/gaim/gaim-assistant.so

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gaim-assistant.so ${PREFIX}/lib/gaim

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
