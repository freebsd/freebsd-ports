# New ports collection makefile for:	dillo-i18n
# Date created:			2005-12-11
# Whom:               		Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#
# Tunables:
# WITH_DILLO_META-REFRESH:	make dillo accept the meta-refresh tag
# WITHOUT_DILLO_TABS:		disable support for tabbed browsing
# WITHOUT_DILLO_ANTIALIAS:	disable support for antialiased display
#
# Please see www/dillo for any general tunables not listed here.
#
# XXX:
# SSL support is currently broken in this version of the i18n patchset:
# On FreeBSD 4 with OpenSSL 0.9.7d, the configure script refuses to enable
# ssl at all and on FreeBSD 5 and up, linking is broken.

PORTREVISION=	2
PKGNAMESUFFIX=	-i18n

PATCH_SITES=	http://teki.jpn.ph/pc/software/
PATCHFILES=	dillo-0.8.5-i18n-misc-20060105.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A fast, small graphical Web browser with support for i18n

MD5_FILE=	${.CURDIR}/distinfo

MASTERDIR=	${.CURDIR}/../../www/dillo
PKGDIR=		${.CURDIR}
PLIST_SUB=	NLS=""

CONFLICTS=	dillo-[0-9].[0-9].[0-9]*

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.else
# Unfortunately, this option does not work yet; the dpi plugins do not
# build without NLS support anymore.
# I leave this option in in case anyone really wants to fix this in the
# i18n patch.
PLIST_SUB=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
IGNORE=		does not build without NLS support
.endif

.if defined(WITH_DILLO_SSL)
IGNORE=		does not build with SSL support
.endif

.if defined(WITH_DILLO_META-REFRESH)
CONFIGURE_ARGS+=	--enable-meta-refresh
.else
CONFIGURE_ARGS+=	--disable-meta-refresh
.endif

.if defined(WITHOUT_DILLO_TABS)
CONFIGURE_ARGS+=	--disable-tabs
.else
CONFIGURE_ARGS+=	--enable-tabs
.endif

.if !defined(WITHOUT_DILLO_ANTIALIAS)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-anti-alias
.else
CONFIGURE_ARGS+=	--disable-anti-alias
.endif

pre-configure:
.if !defined(WITH_DILLO_META-REFRESH)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITH_DILLO_META-REFRESH=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to make dillo respect the meta-refresh tag."
.endif
.if !defined(WITHOUT_DILLO_TABS)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITHOUT_DILLO_TABS=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to disable support for tabbed browsing."
.endif
.if !defined(WITHOUT_DILLO_ANTIALIAS)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITHOUT_DILLO_ANTIALIAS=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to disable support for antialiased fonts."
.endif
	@${ECHO_CMD} ""

.include "${MASTERDIR}/Makefile"
