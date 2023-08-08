PORTNAME=	sispmctl
DISTVERSION=	4.11
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	CLI tool to manage USB controlled powerstrips produced by GEMBIRD LTD
WWW=		https://sispmctl.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-disable-static --disable-webless
CONFIGURE_ENV=	LIBUSB_CFLAGS="-I/usr/include" \
				LIBUSB_LIBS="-L/usr/lib -lusb"

PLIST_FILES=	bin/sispmctl \
				lib/libsispmctl.so \
				lib/libsispmctl.so.0 \
				lib/libsispmctl.so.0.2.2 \
				man/man1/sispmctl.1.gz

.include <bsd.port.mk>
