# New ports collection makefile for:   pcmanfm
# Date created:                2006/02/03
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pcmanfm
PORTVERSION=	0.1.9.5
CATEGORIES=	x11-fm deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	PCMan File Manager

USE_GNOME=	gtk20 intlhack
USE_GCC=	3.3+
USE_AUTOTOOLS=	libtool:15
USE_X_PREFIX=	yes
USE_FAM=	yes
INSTALLS_SHLIB=	yes

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

.include <bsd.port.mk>
