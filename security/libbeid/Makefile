# $FreeBSD$

PORTNAME=	libbeid
PORTVERSION=	4.0.6.1457
CATEGORIES=	security
MASTER_SITES=	http://tijl.fastmail.fm/mirror/

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Belgian eID support libraries

LICENSE=	LGPL3

LIB_DEPENDS=	libpcsclite.so:${PORTSDIR}/devel/pcsc-lite

USES=		dos2unix libtool pkgconfig tar:xz
USE_AUTOTOOLS=	autoconf:env automake:env libtoolize:env
USE_GNOME=	gtk20

DOS2UNIX_FILES=	common/src/datafile.cpp common/src/logbase.cpp \
		common/src/util.cpp dialogs/src/dialogs.h pkcs11/src/asn1.c \
		pkcs11/src/log.h pkcs11/src/cal.cpp pkcs11/src/cal.h

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

post-patch:
	@${REINPLACE_CMD} -e '/svn_revision/d' -e '/SUBDIRS/s/xpi//' \
		${WRKSRC}/Makefile.am ${WRKSRC}/configure.ac

pre-configure:
	@(cd ${WRKSRC} && ${AUTORECONF} -i -f)

.include <bsd.port.mk>
