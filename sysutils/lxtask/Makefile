# New ports collection makefile for:   lxtask
# Date created:                2008/06/20
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	lxtask
PORTVERSION=	0.1.3
CATEGORIES=	sysutils gnome
MASTER_SITES=	SF/lxde/LXTask%20%28task%20manager%29/LXTask%20${PORTVERSION}

MAINTAINER=	davide.italiano@gmail.com
COMMENT=	A lightweight desktop-independent task manager

USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
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

post-install:
	@${ECHO_CMD} ${PKGMESSAGE}

.include <bsd.port.mk>
