# Created by: Dominique Goncalves <dominique.goncalves@gmail.com>
# $FreeBSD$

PORTNAME=		gnomebaker
PORTVERSION=		0.6.4
PORTREVISION=	5
CATEGORIES=		sysutils gnome
MASTER_SITES=		SF
DIST_SUBDIR=		gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=		CD/DVD recording GUI for Gnome

OPTIONS_DEFINE=		DVD
DVD_DESC=		DVD support

RUN_DEPENDS+=		cdrdao:${PORTSDIR}/sysutils/cdrdao \
			cdrecord:${PORTSDIR}/sysutils/cdrtools

USE_GNOME=		gnomeprefix gnomehack libgnomeui desktopfileutils
GNU_CONFIGURE=		yes
INSTALLS_OMF=		yes
USES=		gettext gmake
USE_GSTREAMER=		vorbis mp3 flac
INSTALLS_ICONS=		yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic

ONLY_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Coredump on amd64, see PR: ports/130972

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVD}
RUN_DEPENDS+=		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
