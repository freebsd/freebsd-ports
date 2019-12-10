# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdbxviewer
PORTVERSION=	0.1
DISTVERSIONPREFIX=v
CATEGORIES=	security

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	ncurses GUI and command-line tool for KeePass2 Database files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libstfl.so:devel/stfl

USE_GITHUB=	yes
GH_ACCOUNT=	max-weller

USES=		ncurses
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	bin/kdbxviewer
ALL_TARGET=

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS} ${LDFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/kdbxviewer ${STAGEDIR}${PREFIX}/bin/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kdbxviewer

.include <bsd.port.mk>
