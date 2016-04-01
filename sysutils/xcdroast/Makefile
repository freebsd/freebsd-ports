# Created by: Oliver Lehmann <Kai_Allard_Liao@gmx.de>
# $FreeBSD$

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.16
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.98alpha16 \
		http://www.xcdroast.org/download/

DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./alpha/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Another X11 frontend to mkisofs/cdrecord

OPTIONS_DEFINE=	GTK2 NONROOT NLS
OPTIONS_DEFAULT=	GTK2
NONROOT_DESC=	Use xcdroast w/o being root

RUN_DEPENDS=	cdrecord:sysutils/cdrtools
BUILD_DEPENDS=	cdrecord:sysutils/cdrtools

USES=		gettext gmake iconv pkgconfig
GNU_CONFIGURE=	yes
WANT_GNOME=	yes

CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

CONFIGURE_ARGS=	--with-cdrtools-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.else
PLIST_SUB=	NLS=""
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=--enable-gtk2
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=--disable-gtk2
USE_GNOME=	gdkpixbuf
.endif

.if ${PORT_OPTIONS:MNONROOT}
CONFIGURE_ARGS+=--enable-nonrootmode
.else
CONFIGURE_ARGS+=--disable-nonrootmode
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ver->minor = ver->patch|& = ver->branch|g' \
		${WRKSRC}/src/xtools.c

pre-everything::
.if ${PORT_OPTIONS:MNONROOT}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
	@${ECHO_MSG} "Are you sure you want this? If not, hit Ctrl+C right now "
	@${ECHO_MSG}
	@${ECHO_MSG} "         This is a security risk! XCDRost will use an own"
	@${ECHO_MSG} "         wrapping utility which gets a SUID Bit after enabling"
	@${ECHO_MSG} "         the non-root mode inside the application!"
	@${ECHO_MSG}
	sleep 5
.endif

.include <bsd.port.mk>
