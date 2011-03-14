# New ports collection makefile for:	xdvshow
# Date created:				2003/05/13
# Whom:					simokawa@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xdvshow
PORTVERSION=	00.2003.09.03
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	http://www.sfc.wide.ad.jp/DVTS/software/xdvshow/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DV/RTP viewer

DEPRECATED=     upstream has disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv

PLIST_FILES=	bin/xdvshow
GNU_CONFIGURE=		YES
USE_AUTOTOOLS=	autoconf
USE_SDL=	sdl

post-patch:
	@${REINPLACE_CMD} \
		-e "s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g" \
		-e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
		-e "s|/usr/X11R6|${LOCALBASE}|g" \
		${WRKSRC}/configure.in
	${REINPLACE_CMD} -e "s|-Werror||" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
