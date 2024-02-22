PORTNAME=	libcaes
DISTVERSION=	alpha-20231120
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/libyal/libcaes/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library to support cross-platform AES encryption
WWW=		https://github.com/libyal/libcaes

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-python --with-openssl=no
CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
USES=		libtool pathfix pkgconfig python
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
