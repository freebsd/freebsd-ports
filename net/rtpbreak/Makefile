# Created by: Prudhvi Krishna <prudhvikrishna@gmail.com>
# $FreeBSD$

PORTNAME=	rtpbreak
PORTVERSION=	1.3a
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://dallachiesa.com/code/rtpbreak/
EXTRACT_SUFX=	.tgz

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
COMMENT=	Detects, reconstructs, and analyzes any RTP session

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

MAKE_ARGS+=	CFLAGS="-Wall -O3 -I${LOCALBASE}/include/libnet11" \
		LIBS="-L${LOCALBASE}/lib/libnet11 -lpcap -lnet"

PLIST_FILES=	bin/rtpbreak

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rtpbreak ${PREFIX}/bin

.include <bsd.port.mk>
