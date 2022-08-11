PORTNAME=		visualworks
PORTVERSION=		7.6
PORTREVISION=		1
CATEGORIES=		lang linux
MASTER_SITES=		http://www.cincomsmalltalk.com/bsdports/${SUBDIR}.old/
DISTFILES=		BaseVisualWorks.tar.gz \
			VM-Linux86.tar.gz
EXTRACT_ONLY=

MAINTAINER=		ports@FreeBSD.org
COMMENT=		High performance Smalltalk environment

# Converted from RESTRICTED
LICENSE=	VISUALWORKS
LICENSE_NAME=	VISUALWORKS
LICENSE_TEXT=	Redistribution is probably not permitted
LICENSE_PERMS=	auto-accept

BROKEN=			does not fetch

DIST_SUBDIR=		${SUBDIR}
SUBDIR=			vwnc${PORTVERSION}

USES=			linux
USE_LINUX=	xorglibs
ONLY_FOR_ARCHS=		i386 amd64
NO_BUILD=		yes
MY_STARTUP_SCRIPT=	visual.sh

OPTIONS_DEFINE=	ATOOLS COM DLLC DST DATABASE DOTNET CONTRIBUTED ARAGON COAST DOME JUN \
		SEASIDE SILVERMARK GEMSTONE I18N OBSOLETE OPENTALK PLUGIN PREVIEW STORE  \
		WEBAPP WEBSERVICES VMLINUX VMWINDOWS VMMAC VMSOLARIS VMAIX VMHPUX VMSGI
OPTIONS_DEFAULT=	DLLC DATABASE SEASIDE STORE

SUB_FILES=	pkg-message

ATOOLS_DESC=	Advanced Tools
COM_DESC=	COM
DLLC_DESC=	DLLC Connect
DST_DESC=	Distributed Smalltalk
DATABASE_DESC=	Database Support
DOTNET_DESC=	DotNet Connect
CONTRIBUTED_DESC=	Contributed
ARAGON_DESC=	Contributed - Aragon
COAST_DESC=	Contributed - COAST
DOME_DESC=	Contributed - DOME
JUN_DESC=	Contributed - Jun 3D Framework
SEASIDE_DESC=	Contributed - Seaside
SILVERMARK_DESC=	Contributed - Silvermark
GEMSTONE_DESC=	Contributed - GemStone Server and Client
I18N_DESC=	Internationalization
OBSOLETE_DESC=	Obsolete stuff
OPENTALK_DESC=	Opentalk
PLUGIN_DESC=	Plugin
PREVIEW_DESC=	Preview Technology
STORE_DESC=	Store
WEBAPP_DESC=	Web Application Framework
WEBSERVICES_DESC=	Web Services
VMLINUX_DESC=	Virtual Machines for Linux ppc/sparc/x86-64
VMWINDOWS_DESC=	Virtual Machines for Windows NT/CEx86/CEarm
VMMAC_DESC=	Virtual Machines for Mac OSX/OSXX11/powermac
VMSOLARIS_DESC=	Virtual Machine for Solaris
VMAIX_DESC=	Virtual Machine for AIX
VMHPUX_DESC=	Virtual Machine for HPUX
VMSGI_DESC=	Virtual Machine for SGI

.include <bsd.port.pre.mk>

.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MATOOLS}
DISTFILES+=	AdvancedTools.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MCOM}
DISTFILES+=	COM.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MDLLC}
DISTFILES+=	DLLC.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MDST}
DISTFILES+=	DST.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MDATABASE} || ${PORT_OPTIONS:MDOTNET}
DISTFILES+=	Database.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MCONTRIBUTED}
DISTFILES+=	Contributed.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MARAGON}
DISTFILES+=	CntrbAragon.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MCOAST}
DISTFILES+=	CntrbCOAST.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MDOME}
DISTFILES+=	CntrbDome.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MJUN}
DISTFILES+=	CntrbJun.tar.gz \
		CntrbHeeg.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MSEASIDE}
DISTFILES+=	CntrbSeaside.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MSILVERMARK}
DISTFILES+=	CntrbSilverMark.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MGEMSTONE}
DISTFILES+=	CntrbGemStoneClient.tar.gz \
		CntrbGemStoneSvrLinux.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MI18N}
DISTFILES+=	I18NCatalogs.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MOBSOLETE}
DISTFILES+=	Obsolete.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MOPENTALK}
DISTFILES+=	Opentalk.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MPLUGIN}
DISTFILES+=	Plugin.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MPREVIEW}
DISTFILES+=	Preview.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MSTORE}
DISTFILES+=	Store.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MVMAIX}
DISTFILES+=	VM-AIX.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MVMHPUX}
DISTFILES+=	VM-HPUX.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MVMMAC}
DISTFILES+=	VM-MacOSX.tar.gz \
		VM-MacOSXX11.tar.gz \
		VM-Powermac.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MVMSGI}
DISTFILES+=	VM-SGI.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MVMSOLARIS}
DISTFILES+=	VM-Solaris.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MVMWINDOWS}
DISTFILES+=	VM-Windows.tar.gz \
		VM-WinCEARM.tar.gz \
		VM-WinCEx86.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MVMLINUX}
DISTFILES+=	VM-LinuxPPC.tar.gz \
		VM-LinuxSPARC.tar.gz \
		VM-LinuxX86_64.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MWEBAPP}
DISTFILES+=	WebApplicationServer.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || ${PORT_OPTIONS:MWEBSERVICES}
DISTFILES+=	WebServices.tar.gz
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@for f in ${DISTFILES}; do tar xzpf ${DISTDIR}/${DIST_SUBDIR}/$$f -C ${STAGEDIR}${DATADIR}; done
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/${MY_STARTUP_SCRIPT}
	@${ECHO_CMD} "VISUALWORKS=${DATADIR}" >> ${WRKDIR}/${MY_STARTUP_SCRIPT}
	@${ECHO_CMD} "export VISUALWORKS" >> ${WRKDIR}/${MY_STARTUP_SCRIPT}
	@${ECHO_CMD} "${DATADIR}/bin/linux86/visual \$$*" >> ${WRKDIR}/${MY_STARTUP_SCRIPT}
	@${INSTALL_SCRIPT} ${WRKDIR}/${MY_STARTUP_SCRIPT} ${STAGEDIR}${DATADIR}
	@${LN} -s ${DATADIR}/${MY_STARTUP_SCRIPT} ${STAGEDIR}${PREFIX}/bin/visual

.include <bsd.port.post.mk>
