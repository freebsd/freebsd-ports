# New ports collection makefile for:	gaim-guifications
# Date created:		2004-05-04
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	pidgin-guifications
PORTVERSION=	2.16
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	http://downloads.guifications.org/plugins/Guifications2/

MAINTAINER=	ports@c0decafe.net
COMMENT=	Plugin to add msn style "toaster" popups to Pidgin

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"CPPFLAGS=-I${LOCALBASE}/include" "LIBS=-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-extract:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's#\([@(]\)PIDGIN_LIBDIR\([@)]\)#\1libdir\2#' \
		-e 's#\([@(]\)PIDGIN_DATADIR\([@)]\)#\1datadir\2#'
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
