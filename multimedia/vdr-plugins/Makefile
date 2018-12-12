# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugins
PORTVERSION=	1.7.29
PORTREVISION=	6
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - plugin metaport

RUN_DEPENDS+=	vdr:multimedia/vdr

USES=		metaport

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

VDRDIR=		${LOCALBASE}/lib/vdr

.for OPT in ${OPTIONS_DEFINE}
. if ${OPTIONS_DEFINE:MREELSCAN} == ${OPT}
${OPT}_RUN_DEPENDS=	${VDRDIR}/libvdr-reelchannelscan.so.${PORTVERSION}:multimedia/vdr-plugin-reelchannelscan
. elif ${OPTIONS_DEFINE:MSTREAMDEV} == ${OPT}
${OPT}_RUN_DEPENDS=	${VDRDIR}/libvdr-${OPT:tl}-server.so.${PORTVERSION}:multimedia/vdr-plugin-${OPT:tl}
. elif ${OPTIONS_DEFINE:MLIVE} == ${OPT}
${OPT}_RUN_DEPENDS=	${VDRDIR}/libvdr-${OPT:tl}.so.${PORTVERSION}:www/vdr-plugin-${OPT:tl}
. else
${OPT}_RUN_DEPENDS=	${VDRDIR}/libvdr-${OPT:tl}.so.${PORTVERSION}:multimedia/vdr-plugin-${OPT:tl}
. endif
.endfor

.include <bsd.port.mk>
