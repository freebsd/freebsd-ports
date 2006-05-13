# New ports collection makefile for:	clearlooks
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#      $MCom: ports/x11-themes/clearlooks/Makefile,v 1.4 2005/10/14 20:39:59 adamw Exp $
#

PORTNAME?=	clearlooks
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	clearlooks
DISTNAME=	clearlooks-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT?=	GTK+ 2.x engine based on Bluecurve

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

.if defined(PORTNAME) && ${PORTNAME} == "clearlooks"
OPTIONS+=	ANIMATION "Enable experimental animated progressbars" Off \
		METACITY "Depend on MetaCity Theme" On
.endif

.include <bsd.port.pre.mk>

.if ${PORTNAME} == "clearlooks"
CONFLICTS+=	gtk-engines2-[0-9]* clearlooks-themes[0-9]*
PLIST_SUB+=	ENGINE=""
.else
CONFLICTS+=	clearlooks-[0-9]*

BUILD_DEPENDS+=	${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS+=	${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2

BUILD_WRKSRC=	${WRKSRC}/themes
INSTALL_WRKSRC=	${WRKSRC}/themes

PLIST_SUB+=	ENGINE="@comment "
.endif

.if !defined(WITHOUT_METACITY) && ${PORTNAME}=="clearlooks"
RUN_DEPENDS+=	${X11BASE}/share/gnome/themes/Clearlooks/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/clearlooks-metacity
.endif

.if defined(WITH_ANIMATION)
CONFIGURE_ARGS+=	--enable-animation
.endif

.if ${PORTNAME} == "clearlooks"
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

.include <bsd.port.post.mk>
