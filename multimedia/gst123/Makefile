# New ports collection makefile for:	gst123
# Date created:				Wed December 8, 2010
# Whom:					Herbert J. Skuhra <h.skuhra@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gst123
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://space.twc.de/~stefan/gst123/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	A command-line tool to play audio and video files

LICENSE=	LGPL20

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GSTREAMER=	good
CONFIGURE_ENV=	NCURSES5_CONFIG=/usr/bin/true
LDFLAGS+=	-lncurses

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
