# New ports collection makefile for:	gaim-guifications
# Date created:		2004-05-04
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	guifications
PORTVERSION=	2.9
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gaim-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Plugin to add msn style "toaster" popups to Gaim

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libintl-prefix=${LOCALBASE}
CONFIGURE_ENV+="CPPFLAGS=-I${LOCALBASE}/include" "LIBS=-L${LOCALBASE}/lib"
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's#\([@(]\)GAIM_LIBDIR\([@)]\)#\1libdir\2#' \
		-e 's#\([@(]\)GAIM_DATADIR\([@)]\)#\1datadir\2#'

.include <bsd.port.mk>
