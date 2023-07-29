PORTNAME=	sispmctl
PORTVERSION=	4.11
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	SIS-PM Control for Linux
WWW=		https://sispmctl.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf dos2unix libtool pkgconfig
DOS2UNIX_FILES=	src/web2/index.html src/web3/index.html
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBUSB_CFLAGS="-I/usr/include" \
		LIBUSB_LIBS="-L/usr/lib -lusb"

post-install:
	${LN} -s httpd/skin2 ${STAGEDIR}${PREFIX}/share/doc/sispmctl/skin

.include <bsd.port.mk>
