# New Ports Collection Makefile for:	sim-icq
# Date created:				4 Nov 2002
# Whom:					Josef El-Rayes <j.el-rayes@daemon.li>
#
# $FreeBSD$

PORTNAME=	simicq
PORTVERSION=	0.8
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/mi/m-i/}
DISTNAME=	${PORTNAME:S/icq//}-${PORTVERSION}

MAINTAINER=	j.el-rayes@daemon.li

USE_GMAKE=	yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	 --disable-fast-perl \
		--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITHOUT_KDE)
CONFIGURE_ARGS+=	--disable-kde --enable-mt
USE_REINPLACE=	yes
.else
USE_KDELIBS_VER=	3
.endif

post-patch:
.if defined(WITHOUT_KDE)
	${REINPLACE_CMD} -e "s,qtlib=\"qt\",qtlib=\"qt-mt -pthread\"," ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
