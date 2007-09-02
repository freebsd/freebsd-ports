# New ports collection makefile for:	grsync
# Date created:		24 August 2007
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	grsync
PORTVERSION=	0.6
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.opbyte.it/release/ \
		GENTOO/distfiles \
		LOCAL/chinsan

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	GTK frontend for rsync

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		grsync.1 grsync-batch.1

.include <bsd.port.mk>
