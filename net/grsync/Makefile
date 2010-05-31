# New ports collection makefile for:	grsync
# Date created:		24 August 2007
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	grsync
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.opbyte.it/release/ \
		GENTOO/distfiles \
		LOCAL/chinsan

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	GTK frontend for rsync

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_GNOME=	gtk20 desktopfileutils
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		grsync.1 grsync-batch.1

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} 's/^ALL_LINGUAS=.*/ALL_LINGUAS=""/' \
		${WRKSRC}/configure
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
