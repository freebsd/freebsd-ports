# Created by: Jung-uk Kim <jkim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asusoled
PORTVERSION=	0.10
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Utility for ASUS USB OLED Display

LICENSE=	GPLv2

RUN_DEPENDS=	${FONTDIR}/TTF/luxisr.ttf:${PORTSDIR}/x11-fonts/font-bh-ttf

USE_SDL=	image sdl ttf
USE_RC_SUBR=	asusoled oled_clock

PORTDATA=	asus.png asus_clock.png
PORTDOCS=	README.FreeBSD
PLIST_FILES=	sbin/asusoled
SUB_FILES=	pkg-message

MAKE_ARGS+=	TTF_FONT=${FONTDIR}/TTF/luxisr.ttf

FONTDIR?=	${LOCALBASE}/lib/X11/fonts

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/asusoled ${STAGEDIR}${PREFIX}/sbin
.if !defined(NOPORTDATA)
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in ${PORTDATA}
	@${INSTALL_DATA} ${WRKSRC}/data/${i} ${STAGEDIR}${DATADIR}
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PKGMESSAGE} ${STAGEDIR}${DOCSDIR}/README.FreeBSD
.endif

.include <bsd.port.mk>
