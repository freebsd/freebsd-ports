# New ports collection makefile for:	worker
# Date created:				14 March 2001
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	worker
PORTVERSION=	2.16.5
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/worker/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	simond@irrelevant.org
COMMENT=	X11 File Manager based on Directory Opus

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_BZIP2=	yes

MANLANG=	"" fr it
MAN1=		worker.1

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-libxpkmaster
OPTIONS=	XFT "Enable experimental xft support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_XFT)
USE_XORG+=	xft
CONFIGURE_ARGS+=	--enable-xft
.endif

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

pre-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-patch:
.for f in aa.pattern_rename.sh cd2flac.sh cd2mp3.sh cd2ogg.sh cd2wav.sh xeditor
	${REINPLACE_CMD} -e 's|/bin/bash|/usr/local/bin/bash|g' \
		${WRKSRC}/scripts/${f}
.endfor

.include <bsd.port.post.mk>
