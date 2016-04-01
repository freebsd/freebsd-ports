# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	wxMaxima
PORTVERSION=	14.12.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTVERSION}
DISTFILES=	${PORTNAME:tl}-${PORTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WxWidgets GUI for the computer algebra system maxima

LICENSE=	GPLv2

RUN_DEPENDS=	maxima:math/maxima

CONFIGURE_ARGS=	--program-prefix=

GNU_CONFIGURE=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

USES=		desktop-file-utils gettext
USE_WX=		2.8

WX_UNICODE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:tl}-${PORTVERSION}
WX_COMPS=	wx
WX_CONF_ARGS=	absolute

post-install:
	@${LN} -s ../wxMaxima/wxmaxima.png ${STAGEDIR}${PREFIX}/share/pixmaps/wxmaxima.png
	@${LOCALBASE}/bin/desktop-file-install \
		--mode=${SHAREMODE} --dir=${STAGEDIR}${DESKTOPDIR} \
		${WRKSRC}/${PORTNAME:tl}.desktop

.include <bsd.port.mk>
