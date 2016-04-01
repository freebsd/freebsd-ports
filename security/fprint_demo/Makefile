# Created by: barner
# $FreeBSD$

PORTNAME=	fprint_demo
PORTVERSION=	20080303
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	DEBIAN/pool/main/f/${PORTNAME:C/_/-/}
DISTNAME=	${PORTNAME:C/_/-/}_${PORTVERSION}git.orig

MAINTAINER=	lichray@gmail.com
COMMENT=	Demo and test application for libfprint

LIB_DEPENDS=	libfprint.so:security/libfprint

GNU_CONFIGURE=	yes
USES=		autoreconf pkgconfig desktop-file-utils
USE_GNOME=	atk glib20 gtk20 pango
INSTALLS_ICONS=	yes

WRKSRC=	${WRKDIR}

CONFIGURE_ENV+=	CRYPTO_CFLAGS=-I${OPENSSLINC} \
		CRYPTO_LIBS=-lcrypto
CFLAGS+=	-DHAVE_MEMMEM

.include <bsd.port.mk>
