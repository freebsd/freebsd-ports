# $FreeBSD$

PORTNAME=	sblim-wbemcli
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/sblim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	CLI for Web Based Enterprise Management by SBLIM

BUILD_DEPENDS=	libwww-config:${PORTSDIR}/www/libwww
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_BZIP2=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
MAKE_ARGS=	RM="${RM} -f"
MAN1=		wbemcli.1

NO_STAGE=	yes
.include <bsd.port.mk>
