# New ports collection makefile for:	xcdroast
# Date Created:		28 Sep 2000
# Whom:			Oliver Lehmann <Kai_Allard_Liao@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.15
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.xcdroast.org/download/:src \
		http://www.xcdroast.org/xcdr098/patches/:patch
MASTER_SITE_SUBDIR=	xcdroast
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./alpha/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src new_configure.tar.gz:patch

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Another X11 frontend to mkisofs/cdrecord

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	253

CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

CONFIGURE_ARGS=	--with-cdrtools-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}

MAN1=		xcdroast.1

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
	@${ECHO} "      WITH_GTK2=yes"
	@${ECHO} "         enables gtk2 support"
	@${ECHO} ""

.endif

pre-patch:
	${CP} ${WRKDIR}/aclocal.m4 ${WRKSRC}
	${CP} ${WRKDIR}/configure ${WRKSRC}
	${CP} ${WRKDIR}/configure.in ${WRKSRC}
.include <bsd.port.mk>
