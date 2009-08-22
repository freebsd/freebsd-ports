# New ports collection makefile for:	xcdroast
# Date Created:		28 Sep 2000
# Whom:			Oliver Lehmann <Kai_Allard_Liao@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.16
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.98alpha16 \
		http://www.xcdroast.org/download/

DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./alpha/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Another X11 frontend to mkisofs/cdrecord

OPTIONS=	GTK2	"Enable GTK2 support"		on  \
		NONROOT	"Use xcdroast w/o being root"	off \
		NLS	"Native language support"	on

USE_GETTEXT=	yes
USE_CDRTOOLS=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

CONFIGURE_ARGS=	--with-cdrtools-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}

MAN1=		xcdroast.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.else
PLIST_SUB=	NLS=""
.endif

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=--enable-gtk2
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=--disable-gtk2
USE_GNOME=	gdkpixbuf
.endif

.if defined(WITH_NONROOT)
CONFIGURE_ARGS+=--enable-nonrootmode
.else
CONFIGURE_ARGS+=--disable-nonrootmode
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ver->minor = ver->patch|& = ver->branch|g' \
		${WRKSRC}/src/xtools.c

pre-everything::
.if defined(WITH_NONROOT)
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

.include <bsd.port.post.mk>
