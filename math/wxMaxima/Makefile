# New ports collection makefile for:	wxMaxima
# Date created:		2005-07-12
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	wxMaxima
PORTVERSION=	0.7.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	nivit@email.it
COMMENT=	A wxWidgets GUI for the computer algebra system maxima

LIB_DEPENDS=	wx_baseu-2.6:${PORTSDIR}/x11-toolkits/wxgtk26-unicode
RUN_DEPENDS=	maxima:${PORTSDIR}/math/maxima

USE_GETTEXT=	yes
USE_GNOME=	libxml2
WXGTK_CONFIG?=	${X11BASE}/bin/wxgtk2u-2.6-config
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WXGTK_CONFIG} \
		--program-prefix=

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
