# New ports collection makefile for: gnomebaker
# Date created:        2005-02-20
# Whom:                Dominique Goncalves <dominique.goncalves@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		gnomebaker
PORTVERSION=		0.6.4
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnomebaker
DIST_SUBDIR=		gnome2

MAINTAINER=		dominique.goncalves@gmail.com
COMMENT=		A CD/DVD recording GUI for Gnome

OPTIONS=		DVD "Enable DVD support" off

USE_GNOME=		gnomeprefix gnomehack libgnomeui desktopfileutils
USE_CDRTOOLS=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
INSTALLS_OMF=		yes
USE_GETTEXT=		yes
USE_GSTREAMER=		vorbis mp3 flac
INSTALLS_ICONS=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -export-dynamic"

ONLY_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Coredump on amd64, see PR: ports/130972 

.include <bsd.port.pre.mk>

RUN_DEPENDS+=		cdrdao:${PORTSDIR}/sysutils/cdrdao

.if defined(WITH_DVD)
RUN_DEPENDS+=		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
