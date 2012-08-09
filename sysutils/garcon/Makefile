# New ports collection makefile for:	garcon
# Date created:				11 January 2011
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	garcon
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 essential utilities and scripts

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 intltool intlhack
USE_XFCE=	configenv libutil
USE_PKGCONFIG=	build

CONFIGURE_ARGS+=--disable-gtk-doc-html

OPTIONS_DEFINE=		DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if empty(PORT_OPTIONS:MNLS)
post-patch:
	@${REINPLACE_CMD} -e 's|	po||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
