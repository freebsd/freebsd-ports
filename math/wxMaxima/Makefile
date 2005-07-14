# New ports collection makefile for:	wxMaxima
# Date created:		2005-07-12
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	wxMaxima
PORTVERSION=	0.6.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	nivit@email.it
COMMENT=	A wxWidgets GUI for the computer algebra system maxima

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24 \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	maxima:${PORTSDIR}/math/maxima

WXGTK_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WXGTK_CONFIG} \
		--program-prefix=

.include <bsd.port.mk>
