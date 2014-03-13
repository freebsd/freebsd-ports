# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugins
PORTVERSION=	1.7.29
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - plugin metaport

RUN_DEPENDS+=	vdr:${PORTSDIR}/multimedia/vdr

NO_BUILD=	yes

OPTIONS_DEFINE=	CONTROL EPGSEARCH FEMON INFOSATEPG IPTV OSDPIP \
		OSDTELETEXT REELSCAN REMOTE SKINENIGMANG STREAMDEV \
		TTXTSUBS WIRBELSCAN XINELIBOUTPUT LIVE UPNP \
		SLEEPTIMER XVDR EEPG VDRMANAGER SOFTHDDEVICE \
		EXTRECMENU VNSISERVER MARKAD

CONTROL_DESC=		telnet control
EPGSEARCH_DESC=		EPG search
FEMON_DESC=		frontend monitor
INFOSATEPG_DESC=	infosat EPG data via satellite
IPTV_DESC=		IP television
OSDPIP_DESC=		picture-in-picture
OSDTELETEXT_DESC=	OSD teletext
REELSCAN_DESC=		Reel channelscan
REMOTE_DESC=		non-lirc remote control (experimental)
SKINENIGMANG_DESC=	Enigma-NG skin
STREAMDEV_DESC=		stream device (server and client)
TTXTSUBS_DESC=		teletext subtitle plugin
WIRBELSCAN_DESC=	Wirbelscan
XINELIBOUTPUT_DESC=	xineliboutput plugin/viewer
LIVE_DESC=		live web plugin
UPNP_DESC=		UPnP/DLNA plugin (alpha!)
SLEEPTIMER_DESC=	sleep timer plugin
XVDR_DESC=		XVDR plugin (for connecting XBMC PVR)
EEPG_DESC=		extended EPG plugin (for UK/NL/etc.)
VDRMANAGER_DESC=	plugin for VDR-Manager Android clients
SOFTHDDEVICE_DESC=	softhddevice plugin
EXTRECMENU_DESC=	extended recordings menu plugin
VNSISERVER_DESC=	VNSI server (for XBMC PVR branch - old)
MARKAD_DESC=		MarkAd plugin

OPTIONS_DEFAULT=	CONTROL EPGSEARCH FEMON INFOSATEPG IPTV OSDPIP \
		OSDTELETEXT REELSCAN REMOTE SKINENIGMANG STREAMDEV \
		TTXTSUBS WIRBELSCAN XINELIBOUTPUT LIVE \
		SLEEPTIMER EEPG VDRMANAGER EXTRECMENU VNSISERVER

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONTROL}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-control.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-control
.endif
.if ${PORT_OPTIONS:MEPGSEARCH}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-epgsearch.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-epgsearch
.endif
.if ${PORT_OPTIONS:MFEMON}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-femon.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-femon
.endif
.if ${PORT_OPTIONS:MINFOSATEPG}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-infosatepg.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-infosatepg
.endif
.if ${PORT_OPTIONS:MIPTV}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-iptv.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-iptv
.endif
.if ${PORT_OPTIONS:MOSDPIP}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-osdpip.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-osdpip
.endif
.if ${PORT_OPTIONS:MOSDTELETEXT}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-osdteletext.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-osdteletext
.endif
.if ${PORT_OPTIONS:MREELSCAN}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-reelchannelscan.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-reelchannelscan
.endif
.if ${PORT_OPTIONS:MREMOTE}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-remote.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-remote
.endif
.if ${PORT_OPTIONS:MSKINENIGMANG}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-skinenigmang.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-skinenigmang
.endif
.if ${PORT_OPTIONS:MSTREAMDEV}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-streamdev-server.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-streamdev
.endif
.if ${PORT_OPTIONS:MTTXTSUBS}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-ttxtsubs.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-ttxtsubs
.endif
.if ${PORT_OPTIONS:MWIRBELSCAN}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-wirbelscan.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-wirbelscan
.endif
.if ${PORT_OPTIONS:MXINELIBOUTPUT}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-xineliboutput.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-xineliboutput
.endif
.if ${PORT_OPTIONS:MLIVE}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-live.so.${PORTVERSION}:${PORTSDIR}/www/vdr-plugin-live
.endif
.if ${PORT_OPTIONS:MUPNP}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-upnp.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-upnp
.endif
.if ${PORT_OPTIONS:MSLEEPTIMER}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-sleeptimer.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-sleeptimer
.endif
.if ${PORT_OPTIONS:MXVDR}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-xvdr.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-xvdr
.endif
.if ${PORT_OPTIONS:MEEPG}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-eepg.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-eepg
.endif
.if ${PORT_OPTIONS:MVNSISERVER}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-vnsiserver5.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-vnsiserver
.endif
.if ${PORT_OPTIONS:MMARKAD}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-markad.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-markad
.endif
.if ${PORT_OPTIONS:MVDRMANAGER}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-vdrmanager.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-vdrmanager
.endif
.if ${PORT_OPTIONS:MSOFTHDDEVICE}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-softhddevice.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-softhddevice
.endif
.if ${PORT_OPTIONS:MEXTRECMENU}
RUN_DEPENDS+=	${LOCALBASE}/lib/vdr/libvdr-extrecmenu.so.${PORTVERSION}:${PORTSDIR}/multimedia/vdr-plugin-extrecmenu
.endif

do-install:	# empty

.include <bsd.port.mk>
