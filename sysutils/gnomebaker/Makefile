# New ports collection makefile for: gnomebaker
# Date created:        2005-02-20
# Whom:                Dominique Goncalves <dominique.goncalves@gmail.com>
#
# $FreeBSD$

PORTNAME=		gnomebaker
PORTVERSION=		0.5.0
PORTREVISION=		3
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnomebaker
DIST_SUBDIR=		gnome2

MAINTAINER=		dominique.goncalves@gmail.com
COMMENT=		A CD/DVD recording GUI for Gnome

OPTIONS=		DVD "Enable DVD support" off \
			CJK "Use cdrtools-cjk instead of cdrtools" off

USE_X_PREFIX=		yes
USE_GNOME=		gnomeprefix gnomehack libgnomeui desktopfileutils
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
INSTALLS_OMF=		yes
USE_GCC=		3.4+
USE_GSTREAMER80=		vorbis mad flac
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

RUN_DEPENDS+=		cdrdao:${PORTSDIR}/sysutils/cdrdao

.if defined(WITH_CJK)
RUN_DEPENDS+=		cdrecord:${PORTSDIR}/sysutils/cdrtools-cjk
.else
RUN_DEPENDS+=		cdrecord:${PORTSDIR}/sysutils/cdrtools
.endif

.if defined(WITH_DVD)
RUN_DEPENDS+=		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
