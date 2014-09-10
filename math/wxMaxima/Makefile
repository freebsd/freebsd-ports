# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	wxMaxima
PORTVERSION=	13.04.2
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME:tl}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WxWidgets GUI for the computer algebra system maxima

LICENSE=	GPLv2

RUN_DEPENDS=	maxima:${PORTSDIR}/math/maxima

USES=		gettext desktop-file-utils
USE_GNOME=	libxml2
USE_WX=		2.8
WX_COMPS=	wx
WX_CONF_ARGS=	absolute
WANT_UNICODE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

post-install:
	@${LN} -s ../wxMaxima/wxmaxima.png ${STAGEDIR}${PREFIX}/share/pixmaps/wxmaxima.png
	@${LOCALBASE}/bin/desktop-file-install \
		--mode=${SHAREMODE} --dir=${STAGEDIR}${DESKTOPDIR} \
		${WRKSRC}/${PORTNAME:tl}.desktop

.include <bsd.port.mk>
