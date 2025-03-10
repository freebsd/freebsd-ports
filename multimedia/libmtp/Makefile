PORTNAME=	libmtp
DISTVERSION=	1.1.22
CATEGORIES=	multimedia audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		SF

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Media Transfer Protocol (MTP) library
WWW=		https://github.com/libmtp/libmtp

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=libosmo-sccp # lib/libmtp.a

USES=		cpe gmake iconv libtool localbase pathfix pkgconfig
CPE_VENDOR=	libmtp_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-doxygen \
		--disable-rpath

OPTIONS_DEFINE=	MTPZ
OPTIONS_DEFAULT=MTPZ

MTPZ_DESC=	Enable functionality to connect to MTPZ devices

MTPZ_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
MTPZ_CONFIGURE_ENABLE=	mtpz

.include <bsd.port.mk>
