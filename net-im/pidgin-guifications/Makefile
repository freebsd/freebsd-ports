# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	pidgin-guifications
PORTVERSION=	2.16
PORTREVISION=	7
CATEGORIES=	net-im
MASTER_SITES=	https://www.mimar.rs/distfiles/

MAINTAINER=	marko.cupac@mimar.rs
COMMENT=	Plugin to add msn style "toaster" popups to Pidgin

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's#\([@(]\)PIDGIN_LIBDIR\([@)]\)#\1libdir\2#' \
		-e 's#\([@(]\)PIDGIN_DATADIR\([@)]\)#\1datadir\2#'

.include <bsd.port.mk>
