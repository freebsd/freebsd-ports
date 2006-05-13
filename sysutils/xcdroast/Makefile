# New ports collection makefile for:	xcdroast
# Date Created:		28 Sep 2000
# Whom:			Oliver Lehmann <Kai_Allard_Liao@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.15
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.xcdroast.org/download/:src \
		http://www.xcdroast.org/xcdr098/patches/:patch
MASTER_SITE_SUBDIR=	xcdroast
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./alpha/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src new_configure.tar.gz:patch

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Another X11 frontend to mkisofs/cdrecord

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools

OPTIONS=	GTK2	"Enable GTK2 support"		off \
		NONROOT	"Use xcdroast w/o being root"	off \
		NLS	"Native language support"	on

USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes

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
PATCH_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
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
	@${ECHO_MSG} "         This is a security risk! XCDRost will use an own"
	@${ECHO_MSG} "         wrapping utility which gets a SUID Bit after enabling"
	@${ECHO_MSG} "         the non-root mode inside the application!"
	@${ECHO_MSG}
	sleep 5
.endif

pre-patch:
	@${CP} ${WRKDIR}/configure ${WRKSRC}
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-patch:
	@${REINPLACE_CMD} -e 's|gint in, out|gsize in, out|g' \
		${WRKSRC}/src/xtools.c
.if defined(WITH_GTK2)
	@cd ${WRKSRC}/po ; for FILE in *.po ; do \
		SOURCE=`${AWK} -F'[=\\\\\\\\]' '/charset=/ { print $$2 }' $$FILE` ; \
		${LOCALBASE}/bin/iconv -f $$SOURCE -t UTF-8 $$FILE > $$FILE.bak ; \
		${MV} $$FILE.bak $$FILE ; \
		${REINPLACE_CMD} -e 's|charset='$$SOURCE'|charset=UTF-8|g' $$FILE ; \
	done
.endif

.include <bsd.port.post.mk>
