# New ports collection makefile for:	clearlooks
# Date created:		2005-02-26
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/clearlooks/Makefile,v 1.8 2007/08/07 04:34:29 mezz Exp $
#

PORTNAME?=	clearlooks
PORTVERSION=	0.6.2
PORTREVISION=	8
CATEGORIES=	x11-themes
MASTER_SITES=	SF/clearlooks/clearlooks/clearlooks%20${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT?=	GTK+ 2.x engine based on Bluecurve

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(PORTNAME) && !defined(PKGNAMESUFFIX)
OPTIONS+=	ANIMATION "Enable experimental animated progressbars" Off \
		METACITY "Depend on MetaCity Theme" On
.endif

.include <bsd.port.pre.mk>

.if !defined(PKGNAMESUFFIX)
CONFLICTS+=	gtk-engines2-[0-9]* clearlooks-themes[0-9]*
PLIST_SUB+=	ENGINE=""
.else
CONFLICTS+=	clearlooks-[0-9]*

BUILD_DEPENDS+=	gtk-engines2>=2.7.5_1:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS+=	gtk-engines2>=2.7.5_1:${PORTSDIR}/x11-themes/gtk-engines2

BUILD_WRKSRC=	${WRKSRC}/themes
INSTALL_WRKSRC=	${WRKSRC}/themes

PLIST_SUB+=	ENGINE="@comment "
.endif

.if !defined(WITHOUT_METACITY) && !defined(PKGNAMESUFFIX)
RUN_DEPENDS+=	${LOCALBASE}/share/themes/Clearlooks/metacity-1/metacity-theme-1.xml:${PORTSDIR}/x11-themes/clearlooks-metacity
.endif

.if defined(WITH_ANIMATION)
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
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure
.if ${PORTNAME} != "clearlooks"
	@${REINPLACE_CMD} -e 's|gtkrc||' \
		${WRKSRC}/themes/Clearlooks/gtk-2.0/Makefile.in
.endif

.include <bsd.port.post.mk>
