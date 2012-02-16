# New ports collection makefile for:	vdr
# Date created:		Sun Oct 17 21:15:34 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugins
PORTVERSION=	1.7.22
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - plugin metaport

NO_BUILD=	yes

OPTIONS=	CONTROL "telnet control" On \
		EPGSEARCH "EPG search" On \
		FEMON "frontend monitor" On \
		INFOSATEPG "infosat EPG data via satellite" On \
		IPTV "IP television" On \
		OSDPIP "picture-in-picture" On \
		OSDTELETEXT "OSD teletext" On \
		REELSCAN "Reel channelscan" On \
		REMOTE "non-lirc remote control (experimental)" On \
		SKINENIGMANG "Enigma-NG skin" On \
		STREAMDEV "stream device (server and client)" On \
		TTXTSUBS "teletext subtitle plugin" On \
		WIRBELSCAN "Wirbelscan" On \
		XINELIBOUTPUT "xineliboutput plugin/viewer" On \
		LIVE "live web plugin" On \
		UPNP "UPnP/DLNA plugin (alpha!)" On \
		SLEEPTIMER "sleep timer plugin" On \
		XVDR "XVDR plugin (for connecting XBMC PVR)" On \
		EEPG "extended EPG plugin (for UK/NL/etc.)" On \
		VNSISERVER "VNSI server (for XBMC PVR branch - old)" Off \
		SOFTDEVICE "softdevice (broken?)" Off \
		MARKAD "MarkAd plugin" Off

.include <bsd.port.options.mk>

.if defined(WITH_CONTROL)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-control.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-control
.endif
.if defined(WITH_EPGSEARCH)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-epgsearch.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-epgsearch
.endif
.if defined(WITH_FEMON)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-femon.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-femon
.endif
.if defined(WITH_INFOSATEPG)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-infosatepg.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-infosatepg
.endif
.if defined(WITH_IPTV)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-iptv.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-iptv
.endif
.if defined(WITH_OSDPIP)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-osdpip.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-osdpip
.endif
.if defined(WITH_OSDTELETEXT)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-osdteletext.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-osdteletext
.endif
.if defined(WITH_REELSCAN)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-reelchannelscan.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-reelchannelscan
.endif
.if defined(WITH_REMOTE)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-remote.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-remote
.endif
.if defined(WITH_SKINENIGMANG)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-skinenigmang.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-skinenigmang
.endif
.if defined(WITH_STREAMDEV)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-streamdev-server.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-streamdev
.endif
.if defined(WITH_TTXTSUBS)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-ttxtsubs.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-ttxtsubs
.endif
.if defined(WITH_WIRBELSCAN)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-wirbelscan.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-wirbelscan
.endif
.if defined(WITH_XINELIBOUTPUT)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-xineliboutput.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-xineliboutput
.endif
.if defined(WITH_LIVE)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-live.so.${PORTVERSION}:${PORTSDIR}/www/vdr-plugin-live
.endif
.if defined(WITH_UPNP)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-upnp.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-upnp
.endif
.if defined(WITH_SLEEPTIMER)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-sleeptimer.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-sleeptimer
.endif
.if defined(WITH_SOFTDEVICE)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-softdevice.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-softdevice
.endif
.if defined(WITH_XVDR)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-xvdr.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-xvdr
.endif
.if defined(WITH_EEPG)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-eepg.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-eepg
.endif
.if defined(WITH_VNSISERVER)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-vnsiserver.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-vnsiserver
.endif
.if defined(WITH_MARKAD)
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-markad.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-markad
.endif

do-install:	# empty

.include <bsd.port.mk>
