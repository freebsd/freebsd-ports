# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	stoken
DISTVERSION=	0.92
CATEGORIES=	security
MASTER_SITES=	SF/stoken

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Software Token for UNIX compatible with RSA SecurID

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libtomcrypt.so:security/libtomcrypt # can alternatively use nettle, potentially port option can be created

USES=		libtool localbase pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

X11_CONFIGURE_WITH=	gtk
X11_DESC=	Build GUI token interface
X11_USE=	GNOME=gtk30,cairo,gdkpixbuf2

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g ; s|^dist_doc_DATA|#dist_doc_DATA|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|LTC_LTC_PKCS_1_V1_5|LTC_PKCS_1_V1_5|g' \
	    ${WRKSRC}/src/stc-tomcrypt.c

.include <bsd.port.mk>
