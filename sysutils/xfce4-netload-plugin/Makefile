# New ports collection makefile for:	xfce-netload-plugin
# Date created:				3 September 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-netload-plugin
PORTVERSION=	1.2.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Network Load plugin for Xfce4

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intltool intlhack
USE_XFCE=	configenv libmenu panel
INSTALLS_ICONS=	yes
USE_PKGCONFIG=	build

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=  yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+= NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+= NLS="@comment "
.endif

do-patch:
	@${REINPLACE_CMD} -e 's, || __FreeBSD_kernel__,,' \
		${WRKSRC}/panel-plugin/net.c \
		${WRKSRC}/panel-plugin/net.h \
		${WRKSRC}/panel-plugin/os.h

.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's|po ||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
