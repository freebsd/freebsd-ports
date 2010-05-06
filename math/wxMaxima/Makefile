# New ports collection makefile for:	wxMaxima
# Date created:		2005-07-12
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	wxMaxima
PORTVERSION=	0.8.5
PORTREVISION=	0
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A wxWidgets GUI for the computer algebra system maxima

RUN_DEPENDS=	maxima:${PORTSDIR}/math/maxima

USE_GETTEXT=	yes
USE_GNOME=	libxml2
USE_WX=		2.8
WX_COMPS=	wx
WX_CONF_ARGS=	absolute
WANT_UNICODE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=

DESKTOP_ENTRIES=	"wxMaxima" "${COMMENT}" "${DATADIR}/wxmaxima.png" \
			"wxmaxima" "Education;Science;Math;" false

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
