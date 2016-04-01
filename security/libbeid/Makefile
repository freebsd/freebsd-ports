# $FreeBSD$

PORTNAME=	libbeid
PORTVERSION=	4.1.11
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Belgian eID PKCS #11 module

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USE_GITHUB=	yes
GH_ACCOUNT=	Fedict
GH_PROJECT=	eid-mw

USES=		autoreconf dos2unix libtool pkgconfig
USE_GNOME=	gtk20

DOS2UNIX_FILES=	cardcomm/pkcs11/src/common/datafile.cpp \
		cardcomm/pkcs11/src/common/logbase.cpp \
		cardcomm/pkcs11/src/common/util.cpp \
		cardcomm/pkcs11/src/dialogs/dialogs.h \
		cardcomm/pkcs11/src/log.h

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --with-gtkvers=2
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} '/^libbeidpkcs11_la_LIBADD =/s/-ldl//' \
		${WRKSRC}/cardcomm/pkcs11/src/Makefile.am

.include <bsd.port.mk>
