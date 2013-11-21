# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	grsync
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.opbyte.it/release/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GTK frontend for rsync

LICENSE=	GPLv2

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		bash:${PORTSDIR}/shells/bash

USE_GNOME=	gtk20
USES=		desktop-file-utils gmake shared-mime-info pkgconfig shebangfix
SHEBANG_FILES=	src/grsync-batch
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-unity

INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} 's/^ALL_LINGUAS=.*/ALL_LINGUAS=""/' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
