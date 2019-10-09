# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	grsync
PORTVERSION=	1.2.6
CATEGORIES=	net
MASTER_SITES=	http://www.opbyte.it/release/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GTK frontend for rsync

LICENSE=	GPLv2

RUN_DEPENDS=	rsync:net/rsync \
		bash:shells/bash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-unity
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		desktop-file-utils gettext gmake gnome \
		pkgconfig shared-mime-info shebangfix
USE_GNOME=	gtk20 intltool
SHEBANG_FILES=	src/grsync-batch

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
