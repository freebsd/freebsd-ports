# New ports collection makefile for:	rtpbreak
# Date created:		16 February 2008
# Whom:			Prudhvi Krishna <prudhvikrishna@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rtpbreak
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://xenion.antifork.org/rtpbreak/
EXTRACT_SUFX=	.tgz

MAINTAINER=	prudhvikrishna@gmail.com
COMMENT=	Detects, reconstructs and analyzes any RTP session

BUILD_DEPENDS=	libnet11-config:${PORTSDIR}/net/libnet

MAKE_ARGS+=	CFLAGS="-Wall -O3 -I${LOCALBASE}/include/libnet11" \
		LIBS="-L${LOCALBASE}/lib/libnet11 -lpcap -lnet"

PLIST_FILES=	bin/rtpbreak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rtpbreak ${PREFIX}/bin

.include <bsd.port.mk>
