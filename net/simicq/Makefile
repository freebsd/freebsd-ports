# New Ports Collection Makefile for:	sim-icq
# Date created:				4 Nov 2002
# Whom:					Josef El-Rayes <j.el-rayes@daemon.li>
#
# $FreeBSD$

PORTNAME=	simicq
PORTVERSION=	0.8.3
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/mi/m-i/}
DISTNAME=	${PORTNAME:S/icq//}-${PORTVERSION}

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	ICQ client which supports Version 8 of the ICQ protocol (ICQ 2001)

USE_GMAKE=	yes
USE_QT_VER=	3
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=--disable-openssl
.endif
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITHOUT_KDE)
CONFIGURE_ARGS+=	--disable-kde --enable-mt
.else
USE_KDELIBS_VER=	3
.endif

post-patch:
.if defined(WITHOUT_KDE)
	${REINPLACE_CMD} -e "s,qtlib=\"qt\",qtlib=\"qt-mt -pthread\"," \
		${WRKSRC}/configure
.endif
	${REINPLACE_CMD} -e 's/-O2//g' ${CONFIGURE_WRKSRC}/configure

.include <bsd.port.mk>
