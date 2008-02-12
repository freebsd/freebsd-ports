# New ports collection makefile for:	bsdadminscripts
# Date created:		15 May 2006
# Whom:			Dominic Fandrey <lon_kamikaze@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	bsdadminscripts
PORTVERSION=	4.2
CATEGORIES=	sysutils ports-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	A small collection of administration scripts

OPTIONS+=	BUILDFLAGS "Build configuration system" On
OPTIONS+=	PKG_LIBCHK "Check for links against missing libraries" On
OPTIONS+=	PKG_VALIDATE "Check for broken and missing files" On
OPTIONS+=	PORTCONFIG "Run common make targets on several ports" On
OPTIONS+=	RCSTART "Use rc scripts based on PROVIDE" On

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
NO_BUILD=	yes
MANCOMPRESSED=	no

MAN1=		bsdadminscripts.1

RC_SCRIPTS=	start stop restart status onestart onestop onerestart onestatus
PORT_SCRIPTS=	config build clean fetch package \
		config-recursive fetch-recursive
BUILDFLAGS_SCRIPTS=	buildflags.awk
BUILDFLAGS_FILES=	buildflags.mk
BUILDFLAGS_ETC=	buildflags.conf.sample

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_RCSTART)
PLIST_FILES+=	${RC_SCRIPTS:S,^,sbin/rc,}
MAN1+=		rcstart.1
.endif

.if !defined(WITHOUT_PORTCONFIG)
PLIST_FILES+=	${PORT_SCRIPTS:S,^,sbin/port,}
MAN1+=		portconfig.1
.endif

.if !defined(WITHOUT_BUILDFLAGS)
PLIST_FILES+=	${BUILDFLAGS_FILES:S,^,${DATADIR_REL}/,}
PLIST_FILES+=	${BUILDFLAGS_SCRIPTS:S,^,${DATADIR_REL}/,}
ETC_FILES+=	${BUILDFLAGS_ETC}
PLIST_DIRS+=	${DATADIR_REL}
MAN1+=		buildflags.mk.1 buildflags.conf.1 buildflags.awk.1
.endif

.if !defined(WITHOUT_PKG_VALIDATE)
PLIST_FILES+=	sbin/pkg_validate
MAN1+=		pkg_validate.1
.endif

.if !defined(WITHOUT_PKG_VALIDATE)
PLIST_FILES+=	sbin/pkg_libchk
MAN1+=		pkg_libchk.1
.endif

PLIST_FILES+=	${ETC_FILES:S,^,etc/,}

do-install:
.if !defined(WITHOUT_RCSTART)
	@${ECHO_MSG} "===>  Installing rcstart."
	@${INSTALL_SCRIPT} ${WRKSRC}/rcstart ${PREFIX}/sbin/
.for _link in ${RC_SCRIPTS:Nstart}
	@${LN} ${PREFIX}/sbin/rcstart ${PREFIX}/sbin/rc${_link}
.endfor
.endif
.if !defined(WITHOUT_PORTCONFIG)
	@${ECHO_MSG} "===>  Installing portconfig."
	@${INSTALL_SCRIPT} ${WRKSRC}/portconfig ${PREFIX}/sbin/
.for _link in ${PORT_SCRIPTS:Nconfig}
	@${LN} ${PREFIX}/sbin/portconfig ${PREFIX}/sbin/port${_link}
.endfor
.endif
.if !defined(WITHOUT_BUILDFLAGS)
	@${ECHO_MSG} "===>  Installing buildflags."
	@${MKDIR} ${DATADIR}
.for _file in ${BUILDFLAGS_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${_file} ${DATADIR}
.endfor
.for _file in ${BUILDFLAGS_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${_file} ${DATADIR}
.endfor
.endif
.if !defined(WITHOUT_PKG_LIBCHK)
	@${ECHO_MSG} "===>  Installing pkg_libchk."
	@${INSTALL_SCRIPT} ${WRKSRC}/pkg_libchk ${PREFIX}/sbin/
.endif
.if !defined(WITHOUT_PKG_VALIDATE)
	@${ECHO_MSG} "===>  Installing pkg_validate."
	@${INSTALL_SCRIPT} ${WRKSRC}/pkg_validate ${PREFIX}/sbin/
.endif
.if defined(ETC_FILES)
	@${ECHO_MSG} "===>  Installing configuration samples."
.for _conf in ${ETC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${_conf} ${PREFIX}/etc
.endfor
.endif
.if defined(NOPORTDOCS)
.undef MAN1
.else
	@${ECHO_MSG} "===>  Installing manual pages."
.for _manpage in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${_manpage} ${MANPREFIX}/man/man1/
.endfor
.endif

message:
	@${CAT} ${PKGMESSAGE}

post-install: message
	@${DO_NADA}

.include <bsd.port.post.mk>
