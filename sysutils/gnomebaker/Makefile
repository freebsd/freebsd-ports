# New ports collection makefile for: gnomebaker
# Date created:        2005-02-20
# Whom:                Dominique Goncalves <dominique.goncalves@gmail.com>
#
# $FreeBSD$

PORTNAME=		gnomebaker
PORTVERSION=		0.3
PORTREVISION=		1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnomebaker
DIST_SUBDIR=		gnome2

MAINTAINER=		dominique.goncalves@gmail.com
COMMENT=		A CD/DVD recording GUI for Gnome

RUN_DEPENDS=		cdrecord:${PORTSDIR}/sysutils/cdrtools-cjk \
			cdrdao:${PORTSDIR}/sysutils/cdrdao \
			sox:${PORTSDIR}/audio/sox \
			mpg123:${PORTSDIR}/audio/mpg123 \
			ogg123:${PORTSDIR}/audio/vorbis-tools
LIB_DEPENDS=		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_X_PREFIX=		yes
USE_GNOME=		gnomeprefix gnomehack libgnomeui desktopfileutils
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
INSTALLS_OMF=		yes
USE_GCC=		3.4+
USE_INC_LIBTOOL_VER=	15
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_DVD)
RUN_DEPENDS+=		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITH_DVD=yes to enable dvd support."
	@${ECHO_MSG} ""

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
