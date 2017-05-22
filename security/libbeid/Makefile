# $FreeBSD$

PORTNAME=	libbeid
PORTVERSION=	4.2.8
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

USES=		autoreconf gettext-tools libtool pkgconfig
USE_GNOME=	gtk30

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-p11kit --disable-static --with-gtkvers=3
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/pkgconfig
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pkcs11
	${LN} -s ../libbeidpkcs11.so.0 \
		${STAGEDIR}${PREFIX}/lib/pkcs11/beidpkcs11.so
	${MKDIR} ${STAGEDIR}${PREFIX}/share/p11-kit/modules
	${INSTALL_DATA} ${WRKSRC}/cardcomm/pkcs11/src/beid.module \
		${STAGEDIR}${PREFIX}/share/p11-kit/modules

.include <bsd.port.mk>
