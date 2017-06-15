# $FreeBSD$

PORTNAME=	sblim-wbemcli
PORTVERSION=	1.6.1
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/sblim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	CLI for Web Based Enterprise Management by SBLIM

BUILD_DEPENDS=	libwww-config:www/libwww
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=	tar:bzip2
GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
MAKE_ARGS=	RM="${RM}"

.include <bsd.port.mk>
