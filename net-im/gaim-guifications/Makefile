# New ports collection makefile for:	gaim-guifications
# Date created:		2004-05-04
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	guifications
PORTVERSION=	2.12
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gaim-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Plugin to add msn style "toaster" popups to Gaim

BUILD_DEPENDS=	${LOCALBASE}/include/gaim/config.h:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
GNU_CONFIGURE=	yes

OPTIONS=	NLS "Native Language Support" on

.include <bsd.port.pre.mk>

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
	@${REINPLACE_CMD} -e 's|-g3||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
