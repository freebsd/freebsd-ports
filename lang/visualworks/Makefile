# New ports collection makefile for:	visualworks
# Date created:				17 September 2001
# Whom:					js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=		visualworks
PORTVERSION=		7.6
CATEGORIES=		lang linux
SUBDIR=			vwnc${PORTVERSION}
MASTER_SITES=		http://www.cincomsmalltalk.com/bsdports/${SUBDIR}/
DISTFILES=		BaseVisualWorks.tar.gz \
			VM-Linux86.tar.gz
DIST_SUBDIR=		${SUBDIR}
EXTRACT_ONLY=

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A high performance Smalltalk environment

USE_LINUX=		yes
USE_LINUX_APPS=		xorglibs
ONLY_FOR_ARCHS=		i386
NO_BUILD=		yes
PLIST_FILES=		bin/visual
MY_STARTUP_SCRIPT=	visual.sh

RESTRICTED=		Redistribution is probably not permitted

OPTIONS=	ATOOLS		"Advanced Tools"				off \
		COM		"COM"						off \
		DLLC		"DLLC Connect"					on \
		DST		"Distributed Smalltalk"				off \
		DATABASE	"Database Support"				on \
		DOTNET		"DotNet Connect"				off \
		CONTRIBUTED	"Contributed"					off \
		ARAGON		"Contributed - Aragon"				off \
		COAST		"Contributed - COAST"				off \
		DOME		"Contributed - DOME"				off \
		JUN		"Contributed - Jun 3D Framework"		off \
		SEASIDE 	"Contributed - Seaside"				on \
		SILVERMARK	"Contributed - Silvermark"			off \
		GEMSTONE	"Contributed - GemStone Server and Client"	off \
		I18N		"Internationalization"				off \
		OBSOLETE	"Obsolete stuff"				off \
		OPENTALK	"Opentalk"					off \
		PLUGIN		"Plugin"					off \
		PREVIEW		"Preview Technology"				off \
		STORE		"Store"						on \
		WEBAPP		"Web Application Framework"			off \
		WEBSERVICES	"Web Services"					off \
		VMLINUX		"Virtual Machines for Linux ppc/sparc/x86-64"	off \
		VMWINDOWS	"Virtual Machines for Windows NT/CEx86/CEarm"	off \
		VMMAC		"Virtual Machines for Mac OSX/OSXX11/powermac"	off \
		VMSOLARIS	"Virtual Machine for Solaris"			off \
		VMAIX		"Virtual Machine for AIX"			off \
		VMHPUX		"Virtual Machine for HPUX"			off \
		VMSGI		"Virtual Machine for SGI"			off

.include <bsd.port.pre.mk>

.if make(makesum) || defined(FETCH_ALL) || defined(WITH_ATOOLS)
DISTFILES+=	AdvancedTools.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_COM)
DISTFILES+=	COM.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_DLLC)
DISTFILES+=	DLLC.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_DST)
DISTFILES+=	DST.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_DATABASE) || defined(WITH_DOTNET)
DISTFILES+=	Database.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_CONTRIBUTED)
DISTFILES+=	Contributed.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_ARAGON)
DISTFILES+=	CntrbAragon.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_COAST)
DISTFILES+=	CntrbCOAST.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_DOME)
DISTFILES+=	CntrbDome.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_JUN)
DISTFILES+=	CntrbJun.tar.gz \
		CntrbHeeg.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_SEASIDE)
DISTFILES+=	CntrbSeaside.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_SILVERMARK)
DISTFILES+=	CntrbSilverMark.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_GEMSTONE)
DISTFILES+=	CntrbGemStoneClient.tar.gz \
		CntrbGemStoneSvrLinux.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_I18N)
DISTFILES+=	I18NCatalogs.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_OBSOLETE)
DISTFILES+=	Obsolete.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_OPENTALK)
DISTFILES+=	Opentalk.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_PLUGIN)
DISTFILES+=	Plugin.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_PREVIEW)
DISTFILES+=	Preview.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_STORE)
DISTFILES+=	Store.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_VMAIX)
DISTFILES+=	VM-AIX.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_VMHPUX)
DISTFILES+=	VM-HPUX.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_VMMAC)
DISTFILES+=	VM-MacOSX.tar.gz \
		VM-MacOSXX11.tar.gz \
		VM-Powermac.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_VMSGI)
DISTFILES+=	VM-SGI.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_VMSOLARIS)
DISTFILES+=	VM-Solaris.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_VMWINDOWS)
DISTFILES+=	VM-Windows.tar.gz \
		VM-WinCEARM.tar.gz \
		VM-WinCEx86.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_VMLINUX)
DISTFILES+=	VM-LinuxPPC.tar.gz \
		VM-LinuxSPARC.tar.gz \
		VM-LinuxX86_64.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_WEBAPP)
DISTFILES+=	WebApplicationServer.tar.gz
.endif
.if make(makesum) || defined(FETCH_ALL) || defined(WITH_WEBSERVICES)
DISTFILES+=	WebServices.tar.gz
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@for f in ${DISTFILES}; do tar xzpf ${DISTDIR}/${DIST_SUBDIR}/$$f -C ${DATADIR}; done
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/${MY_STARTUP_SCRIPT}
	@${ECHO_CMD} "VISUALWORKS=${DATADIR}" >> ${WRKDIR}/${MY_STARTUP_SCRIPT}
	@${ECHO_CMD} "export VISUALWORKS" >> ${WRKDIR}/${MY_STARTUP_SCRIPT}
	@${ECHO_CMD} "${DATADIR}/bin/linux86/visual \$$*" >> ${WRKDIR}/${MY_STARTUP_SCRIPT}
	@${INSTALL_SCRIPT} ${WRKDIR}/${MY_STARTUP_SCRIPT} ${DATADIR}
	@${LN} -s ${DATADIR}/${MY_STARTUP_SCRIPT} ${PREFIX}/bin/visual

post-install:
	@${FIND} ${DATADIR} -not -type d \
	  | ${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -d ${DATADIR} -type d \
	  | ${SED} -ne 's,^${DATADIR},@dirrm share/${PORTNAME},p' >> ${TMPPLIST}
	@${ECHO_MSG} " "
	@${ECHO_MSG} " --------------------------- Please note: ---------------------------"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "  To start using VisualWorks, copy the default image to your"
	@${ECHO_MSG} "  home directory:"
	@${ECHO_MSG} "    # ${CP} ${DATADIR}/image/visualnc.im ~"
	@${ECHO_MSG} "  Make it writeable:"
	@${ECHO_MSG} "    # ${CHMOD} u+w ~/visualnc.im"
	@${ECHO_MSG} "  Then run it using:"
	@${ECHO_MSG} "    # visual ~/visualnc.im"
	@${ECHO_MSG} " "
	@${ECHO_MSG} " -------------------- Thanks for your attention! --------------------"
	@${ECHO_MSG} " "

.include <bsd.port.post.mk>
