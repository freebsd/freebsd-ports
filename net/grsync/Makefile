# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	grsync
PORTVERSION=	1.2.6
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.opbyte.it/release/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GTK frontend for rsync

LICENSE=	GPLv2

RUN_DEPENDS=	rsync:net/rsync \
		bash:shells/bash

USE_GNOME=	gtk20 intltool
USES=		desktop-file-utils gettext gmake \
		pkgconfig shared-mime-info shebangfix
SHEBANG_FILES=	src/grsync-batch
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-unity

INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
