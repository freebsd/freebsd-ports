# New ports collection makefile for:	visualworks
# Date created:				17 September 2001
# Whom:					js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=		visualworks
PORTVERSION=		7.3
CATEGORIES=		lang linux
SUBDIR=			vwnc${PORTVERSION}
MASTER_SITES=		http://www.cincomsmalltalk.com/bsdports/${SUBDIR}/
DISTFILES=		BaseVisualWorks.tar.gz \
			VM-Linux86.tar.gz
DIST_SUBDIR=		${SUBDIR}
EXTRACT_ONLY=

MAINTAINER=		chris@chrisburkert.de
COMMENT=		A high performance Smalltalk environment

USE_LINUX?=		yes
ONLY_FOR_ARCHS=		i386
NO_BUILD=		yes
PLIST_FILES=		bin/visual
MY_STARTUP_SCRIPT=	visual.sh

RESTRICTED=		"Redistribution is probably not permitted"
NO_PACKAGE=		${RESTRICTED}
NO_CDROM=		${RESTRICTED}

OPTIONS=	ATOOLS		"Advanced Tools"				off \
		COM		"COM"						off \
		DLLC		"DLLC Connect"					off \
		DST		"Distributed Smalltalk"				off \
		DATABASE	"Database Support"				off \
		GOODIES		"Goodies"					off \
		ARAGON		"Goodies - Aragon"				off \
		COAST		"Goodies - COAST"				off \
		DOME		"Goodies - DOME"				off \
		JUN		"Goodies - Jun 3D Framework"			off \
		SILVERMARK	"Goodies - Silvermark"				off \
		I18N		"Internationalization"				off \
		OPENTALK	"Opentalk"					off \
		PLUGIN		"Plugin"					off \
		PREVIEW		"Preview Technology"				off \
		STORE		"Store"						on \
		WEBAPP		"Web Application Framework"			off \
		WEBSERVICES	"Web Services"					off \

.include <bsd.port.pre.mk>

.if make(makesum) || defined(WITH_ATOOLS)
DISTFILES+=	AdvancedTools.tar.gz
.endif
.if make(makesum) || defined(WITH_COM)
DISTFILES+=	COM.tar.gz
.endif
.if make(makesum) || defined(WITH_DLLC)
DISTFILES+=	DLLC.tar.gz
.endif
.if make(makesum) || defined(WITH_DST)
DISTFILES+=	DST.tar.gz
.endif
.if make(makesum) || defined(WITH_DATABASE)
DISTFILES+=	Database.tar.gz
.endif
.if make(makesum) || defined(WITH_GOODIES)
DISTFILES+=	Goodies.tar.gz
.endif
.if make(makesum) || defined(WITH_ARAGON)
DISTFILES+=	GoodiesAragon.tar.gz
.endif
.if make(makesum) || defined(WITH_COAST)
DISTFILES+=	GoodiesCOAST.tar.gz
.endif
.if make(makesum) || defined(WITH_DOME)
DISTFILES+=	GoodiesDOME.tar.gz
.endif
.if make(makesum) || defined(WITH_JUN)
DISTFILES+=	GoodiesJun.tar.gz
.endif
.if make(makesum) || defined(WITH_SILVERMARK)
DISTFILES+=	GoodiesSilverMark.tar.gz
.endif
.if make(makesum) || defined(WITH_I18N)
DISTFILES+=	I18NCatalogs.tar.gz
.endif
.if make(makesum) || defined(WITH_OPENTALK)
DISTFILES+=	Opentalk.tar.gz
.endif
.if make(makesum) || defined(WITH_PLUGIN)
DISTFILES+=	Plugin.tar.gz
.endif
.if make(makesum) || defined(WITH_PREVIEW)
DISTFILES+=	Preview.tar.gz
.endif
.if make(makesum) || defined(WITH_STORE)
DISTFILES+=	Store.tar.gz
.endif
.if make(makesum) || defined(WITH_WEBAPP)
DISTFILES+=	WebApplicationServer.tar.gz
.endif
.if make(makesum) || defined(WITH_WEBSERVICES)
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
