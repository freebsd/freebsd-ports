# New ports collection makefile for:   ushare
# Date created:        11 December 2006
# Whom:                Volker Theile <votdev@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ushare
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://ushare.geexbox.org/releases/

MAINTAINER=	votdev@gmx.de
COMMENT=	A lightweight UPnP (TM) A/V Media Server

LIB_DEPENDS=	upnp.3:${PORTSDIR}/devel/upnp
BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.sample etc/rc.d/${PORTNAME}
MAN1=		${PORTNAME}.1

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE}/lib \
		--with-libintl-prefix=${LOCALBASE}/lib \
		--with-libupnp-prefix=${LOCALBASE}

.include <bsd.port.pre.mk>

CFLAGS+=	${PTHREAD_LIBS}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${CP} ${WRKSRC}/scripts/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${PORTNAME} ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
