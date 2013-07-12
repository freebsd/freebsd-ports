# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	grsync
PORTVERSION=	1.2.4
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.opbyte.it/release/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GTK frontend for rsync

LICENSE=	GPLv2

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		bash:${PORTSDIR}/shells/bash

USE_GNOME=	gtk20
USES=	desktop-file-utils shared-mime-info
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-unity
USE_GMAKE=	yes

INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		grsync.1 grsync-batch.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/src/grsync-batch
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} 's/^ALL_LINGUAS=.*/ALL_LINGUAS=""/' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
