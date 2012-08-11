# Ports collection makefile for:  asusoled
# Date created:                   2008-09-11
# Whom:                           Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asusoled
PORTVERSION=	0.10
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Utility for ASUS USB OLED Display

RUN_DEPENDS=	${FONTDIR}/TTF/luxisr.ttf:${PORTSDIR}/x11-fonts/font-bh-ttf

USE_SDL=	image sdl ttf
USE_RC_SUBR=	asusoled oled_clock

PORTDATA=	asus.png asus_clock.png
PORTDOCS=	README.FreeBSD
PLIST_FILES=	sbin/asusoled
SUB_FILES=	pkg-message

MAKE_ARGS+=	TTF_FONT=${FONTDIR}/TTF/luxisr.ttf

FONTDIR?=	${LOCALBASE}/lib/X11/fonts

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

post-install:
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
.for i in ${PORTDATA}
	@${INSTALL_DATA} ${WRKSRC}/data/${i} ${DATADIR}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE} > ${WRKSRC}/README.FreeBSD
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.post.mk>
