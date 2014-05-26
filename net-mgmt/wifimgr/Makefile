# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	wifimgr
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://opal.com/freebsd/ports/net-mgmt/wifimgr/ \
		CRITICAL

MAINTAINER=	fbsd@opal.com
COMMENT=	WiFi Networks Manager

USES=		desktop-file-utils pkgconfig tar:bzip2
USE_XORG=	x11
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 901504
MAKE_ENV+=	INSTALL="install -U"
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext pkgconfig
PLIST_SUB+=	NLS=""
.else
CFLAGS+=	-DWITHOUT_NLS
PLIST_SUB+=	NLS="@comment "
MAKE_ENV+=	WITHOUT_NLS=${WITHOUT_NLS}
.endif

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 901504
	@${REINPLACE_CMD} -e 's/-o root -g wheel//' ${WRKSRC}/src/Makefile
.endif

.include <bsd.port.mk>
