# New ports collection makefile for:	xcdroast
# Date Created:		28 Sep 2000
# Whom:			Oliver Lehmann <Kai_Allard_Liao@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.15
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.xcdroast.org/download/
MASTER_SITE_SUBDIR=	xcdroast
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./alpha/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Another X11 frontend to mkisofs/cdrecord

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	253

CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

CONFIGURE_ARGS=	--with-cdrtools-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}

MAN1=		xcdroast.1

.if defined(WITH_GTK2)
RUN_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS+=	glib-2.0.200:${PORTSDIR}/devel/glib20 \
		gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		pcre.0:${PORTSDIR}/devel/pcre
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

pre-everything::
.if defined(WITH_NONROOT)
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
	@${ECHO_MSG} "Are you sure you want this? If not, hit Ctrl+C right now "
	@${ECHO_MSG}
	sleep 5
.else
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_NONROOT=yes"
	@${ECHO} "         Use xcdroast w/o being root."
	@${ECHO} "         But beware!  This is a security risk! XCDRost will use an"
	@${ECHO} "         own wrapping utility which gets a SUID Bit after enabling"
	@${ECHO} "         the non-root mode inside the application!"
	@${ECHO} ""

.endif

.include <bsd.port.mk>
