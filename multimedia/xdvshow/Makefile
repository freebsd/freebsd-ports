# New ports collection makefile for:	xdvshow
# Date created:				2003/05/13
# Whom:					simokawa@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xdvshow
PORTVERSION=	00.2003.09.03
PORTREVISION=	1
#PORTREVISION=	0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.sfc.wide.ad.jp/DVTS/software/xdvshow/
DISTNAME=	${PORTNAME}

MAINTAINER=	simokawa@FreeBSD.org
COMMENT=	DV/RTP viewer

LIB_DEPENDS=	dv.3:${PORTSDIR}/multimedia/libdv

PLIST_FILES=	bin/xdvshow
GNU_CONFIGURE=		YES
USE_AUTOCONF_VER=	253

USE_REINPLACE=		YES

post-patch:
	@${REINPLACE_CMD} \
		-e "s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g" \
		-e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure.in

.include <bsd.port.mk>
