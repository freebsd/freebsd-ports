# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-themes/clearlooks/Makefile,v 1.8 2007/08/07 04:34:29 mezz Exp $

PORTNAME?=	clearlooks
PORTVERSION=	0.6.2
PORTREVISION=	12
CATEGORIES=	x11-themes
MASTER_SITES=	SF/clearlooks/clearlooks/clearlooks%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	GTK+ 2.x engine based on Bluecurve

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pkgconfig tar:bzip2
USE_GNOME=	gtk20

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(PORTNAME) && !defined(PKGNAMESUFFIX)
OPTIONS_DEFINE=	ANIMATION METACITY
OPTIONS_DEFAULT=	METACITY
ANIMATION_DESC=	Enable experimental animated progressbars
METACITY_DESC=	Depend on MetaCity Theme
.endif

.include <bsd.port.options.mk>

.if !defined(PKGNAMESUFFIX)
CONFLICTS+=	gtk-engines2-[0-9]* clearlooks-themes[0-9]*
PLIST_SUB+=	ENGINE=""
.else
CONFLICTS+=	clearlooks-[0-9]*

BUILD_DEPENDS+=	gtk-engines2>=2.7.5_1:x11-themes/gtk-engines2
RUN_DEPENDS+=	gtk-engines2>=2.7.5_1:x11-themes/gtk-engines2

BUILD_WRKSRC=	${WRKSRC}/themes
INSTALL_WRKSRC=	${WRKSRC}/themes

PLIST_SUB+=	ENGINE="@comment "
.endif

.if ${PORT_OPTIONS:MMETACITY} && !defined(PKGNAMESUFFIX)
RUN_DEPENDS+=	${LOCALBASE}/share/themes/Clearlooks/metacity-1/metacity-theme-1.xml:x11-themes/clearlooks-metacity
.endif

.if ${PORT_OPTIONS:MANIMATION}
CONFIGURE_ARGS+=	--enable-animation
.endif

.if !defined(PKGNAMESUFFIX)
pre-everything::
	@if [ -n "`${PKG_INFO} -xI '^gtk-engines2*[0-9]*'`" ]; then \
		${ECHO_MSG} ; \
		${ECHO_MSG} "Gnome/gtk-engine users should use ${PORTSDIR}/x11-themes/clearlooks-themes instead" ; \
		${ECHO_MSG} ; \
		${FALSE}; \
	fi
.endif

post-patch:
.if ${PORTNAME} != "clearlooks"
	@${REINPLACE_CMD} -e 's|gtkrc||' \
		${WRKSRC}/themes/Clearlooks/gtk-2.0/Makefile.in
.endif

.include <bsd.port.mk>
