# New ports collection makefile for:   pcmanfm
# Date created:                2006/02/03
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pcmanfm
PORTVERSION=	0.3.2.2
PORTREVISION=	1
CATEGORIES=	x11-fm deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PCMan File Manager

DEPRECATED=	Unmaintained upstream
EXPIRATION_DATE=	2007-10-18

USE_GNOME=	gtk20 intlhack gnomedesktop
USE_GCC=	3.3+
USE_AUTOTOOLS=	libtool:15
USE_XLIB=	yes
USE_FAM=	yes
USE_LDCONFIG=	yes

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not compile on FreeBSD 5.x
.endif

.include <bsd.port.post.mk>
