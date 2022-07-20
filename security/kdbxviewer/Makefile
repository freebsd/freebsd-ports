PORTNAME=	kdbxviewer
PORTVERSION=	0.1.10
DISTVERSIONPREFIX=v
CATEGORIES=	security

MAINTAINER=	fuz@fuz.su
COMMENT=	Ncurses UI and command-line tool for KeePass2 Database files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libstfl.so:devel/stfl

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	pepa65

ALL_TARGET=	kdbxviewer
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	bin/kdbxviewer

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS} ${LDFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/kdbxviewer ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
