# Created by: Prudhvi Krishna <prudhvikrishna@gmail.com>
# $FreeBSD$

PORTNAME=	rtpbreak
PORTVERSION=	1.3a
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://dallachiesa.com/code/rtpbreak/
EXTRACT_SUFX=	.tgz

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
COMMENT=	Detects, reconstructs, and analyzes any RTP session

BROKEN=		unfetchable

LIB_DEPENDS=	libnet.so:net/libnet

CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lpcap -lnet

MAKE_ARGS=	CFLAGS="${CFLAGS}" LIBS="${LIBS}"

PLIST_FILES=	bin/rtpbreak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rtpbreak ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
