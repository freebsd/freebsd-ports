# ex:ts=8
# Ports collection makefile for:	gambit
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gambit
PORTVERSION=	0.2005.12.12
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of tools for doing computation in game theory

LIB_DEPENDS=	wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk20
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		WX_CONFIG="${X11BASE}/bin/wxgtk2-2.6-config"
MAKE_ENV=	WX_CONFIG="${X11BASE}/bin/wxgtk2-2.6-config"
INSTALLS_SHLIB=	yes

CPPFLAGS=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure
.for file in efgdisplay.cc efgpanel.cc nfgpanel.cc
	@${REINPLACE_CMD} -e '/#if/s: or : || :g' ${WRKSRC}/sources/gui/${file}
.endfor

.include <bsd.port.mk>
