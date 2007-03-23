# New ports collection makefile for:	worker
# Date created:				14 March 2001
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	worker
PORTVERSION=	2.14.4
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/worker/downloads/

MAINTAINER=	simond@irrelevant.org
COMMENT=	X11 File Manager based on Directory Opus

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_BZIP2=	yes

MANLANG=	"" fr it
MAN1=		worker.1

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-libxpkmaster --mandir=${MANPREFIX}/man

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-patch:
.for file in aa.pattern_rename.sh cd2flac.sh cd2mp3.sh cd2ogg.sh cd2wav.sh xeditor
	${REINPLACE_CMD} -e 's|/bin/bash|/usr/local/bin/bash|g' \
		${WRKSRC}/scripts/${file}
.endfor

.include <bsd.port.post.mk>
