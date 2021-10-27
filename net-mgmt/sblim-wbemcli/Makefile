PORTNAME=	sblim-wbemcli
PORTVERSION=	1.6.3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/sblim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CLI for Web Based Enterprise Management by SBLIM

BUILD_DEPENDS=	libwww-config:www/libwww
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		tar:bzip2
GNU_CONFIGURE=	YES
MAKE_ARGS=	RM="${RM}"
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

.include <bsd.port.mk>
