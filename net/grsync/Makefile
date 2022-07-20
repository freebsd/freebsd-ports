PORTNAME=	grsync
PORTVERSION=	1.3.0
CATEGORIES=	net
MASTER_SITES=	http://www.opbyte.it/release/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GTK frontend for rsync

LICENSE=	GPLv2

RUN_DEPENDS=	rsync:net/rsync \
		bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gettext gmake gnome \
		pkgconfig shared-mime-info shebangfix
USE_GNOME=	cairo gtk30 intltool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-unity
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	src/grsync-batch

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
