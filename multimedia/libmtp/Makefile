PORTNAME=	libmtp
PORTVERSION=	1.1.18
CATEGORIES=	multimedia audio
MASTER_SITES=	SF

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Media Transfer Protocol (MTP) library

LICENSE=	LGPL21+

CONFLICTS_INSTALL=libosmo-sccp # lib/libmtp.a

USES=		cpe iconv libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
CPE_VENDOR=	libmtp_project

OPTIONS_DEFINE=	MTPZ
OPTIONS_DEFAULT=MTPZ

MTPZ_DESC=	Enable functionality to connect to MTPZ devices
MTPZ_CONFIGURE_ENABLE=	mtpz
MTPZ_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

.include <bsd.port.mk>
