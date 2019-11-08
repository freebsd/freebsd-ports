# $FreeBSD$

PORTNAME=	asusoled
PORTVERSION=	0.10
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Utility for ASUS USB OLED Display

LICENSE=	GPLv2

RUN_DEPENDS=	${FONTDIR}/TTF/luxisr.ttf:x11-fonts/font-bh-ttf

USES=		sdl
USE_SDL=	image sdl ttf
USE_RC_SUBR=	asusoled oled_clock

PORTDATA=	asus.png asus_clock.png
PORTDOCS=	README.FreeBSD
PLIST_FILES=	sbin/asusoled
SUB_FILES=	pkg-message

MAKE_ARGS+=	TTF_FONT=${FONTDIR}/TTF/luxisr.ttf

FONTDIR?=	${LOCALBASE}/share/fonts

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asusoled ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in ${PORTDATA}
	${INSTALL_DATA} ${WRKSRC}/data/${i} ${STAGEDIR}${DATADIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PKGMESSAGE} ${STAGEDIR}${DOCSDIR}/README.FreeBSD

.include <bsd.port.mk>
