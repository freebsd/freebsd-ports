# New ports collection makefile for:	oleo
# Date created:		3 September 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	oleo
PORTVERSION=	1.99.16
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The GNU spreadsheet for X11 and terminals

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_REINPLACE=	yes
USE_AUTOCONF_VER=213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-x --without-xlt --without-SciPlot

.if defined(WITH_MOTIF)
LIB_DEPENDS+=	plot:${PORTSDIR}/graphics/plotutils \
		Xbae:${PORTSDIR}/x11-toolkits/xbae \
		XmHTML:${PORTSDIR}/x11-toolkits/xmhtml
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-motif
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=	--without-motif
.endif

pre-everything::
.if !defined(WITH_MOTIF)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Motif support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_MOTIF=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"

.include <bsd.port.mk>
