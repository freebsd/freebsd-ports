PORTNAME=	tailcat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Like netcat, over Tailscale's data plane, no control plane
WWW=		https://tailscale.com/tailcat

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/tailscale/tailcat
GO_TARGET=	./cmd/tailcat
GO_BUILDFLAGS=	-tags="${TAILCAT_TAGS}" -ldflags "-s -w \
		-X main.version=${DISTVERSIONPREFIX}${DISTVERSION}"

PLIST_FILES=	bin/tailcat

# Keep the tag list in sync with build-tags.txt:
#   https://github.com/tailscale/tailcat/blob/main/build-tags.txt
TAILCAT_TAGS=	ts_omit_ace,ts_omit_acme,ts_omit_advertiseexitnode,ts_omit_advertiseroutes,ts_omit_appconnectors,ts_omit_aws,ts_omit_bird,ts_omit_cachenetmap,ts_omit_captiveportal,ts_omit_capture,ts_omit_cliconndiag,ts_omit_clientmetrics,ts_omit_clientupdate,ts_omit_cloud,ts_omit_colorable,ts_omit_completion,ts_omit_completion_scripts,ts_omit_conn25,ts_omit_connreject,ts_omit_debug,ts_omit_debugeventbus,ts_omit_debugportmapper,ts_omit_desktop_sessions,ts_omit_dns,ts_omit_dnsresolvecache,ts_omit_doctor,ts_omit_drive,ts_omit_favorites,ts_omit_flashappliance,ts_omit_health,ts_omit_hujsonconf,ts_omit_identityfederation,ts_omit_ipnbus,ts_omit_iptables,ts_omit_kube,ts_omit_linkspeed,ts_omit_linuxdnsfight,ts_omit_listenrawdisco,ts_omit_logtail,ts_omit_netlog,ts_omit_networkmanager,ts_omit_oauthkey,ts_omit_osrouter,ts_omit_outboundproxy,ts_omit_peerapiclient,ts_omit_peerapiserver,ts_omit_portlist,ts_omit_portmapper,ts_omit_posture,ts_omit_qrcodes,ts_omit_relayserver,ts_omit_remoteconfig,ts_omit_resolved,ts_omit_routecheck,ts_omit_runtimemetrics,ts_omit_sdnotify,ts_omit_serve,ts_omit_serviceclientprefs,ts_omit_synology,ts_omit_syslog,ts_omit_syspolicy,ts_omit_systray,ts_omit_taildrop,ts_omit_tailnetlock,ts_omit_tap,ts_omit_tpm,ts_omit_tundevstats,ts_omit_unixsocketidentity,ts_omit_useexitnode,ts_omit_useproxy,ts_omit_usermetrics,ts_omit_useroutes,ts_omit_wakeonlan,ts_omit_webbrowser,ts_omit_webclient

.include <bsd.port.mk>
