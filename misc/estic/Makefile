# Created by: Julian Stacey <jhs@FreeBSD.org>
# $FreeBSD$

PORTNAME=		estic
PORTVERSION=		1.61
PORTREVISION=		2
CATEGORIES=		misc comms
MASTER_SITES=		LOCAL/dinoex
PKGNAMESUFFIX?=		${NOX11_SUFFIX}${PKGNAMESUFFIX2}
DISTFILES=		estic-1.60-sources.zip estic-1.61-patch-from-1.60.zip

MAINTAINER=		dinoex@FreeBSD.org
COMMENT=		Controller for ISDN TK-Anlage (PBX) made by Istec

USES=		ncurses zip
USE_CSTD=	gnu89
USE_CXXSTD=	gnu++98
USE_GCC=	any
NO_WRKSUBDIR=	yes

# Personal Preferences, Where to install.
PBX_VAR=${STAGEDIR}${PREFIX}/var/log/pbx
PBX_ETC=${STAGEDIR}${PREFIX}/etc/pbx
PBX_MAN=${STAGEDIR}${PREFIX}/man/man1
PBX_BIN=${STAGEDIR}${PREFIX}/bin
PBX_DOC=${STAGEDIR}${DOCSDIR}
ESTIC=${WRKSRC}/estic
AREACODE_DATAFILE=${PREFIX}/etc/pbx/areacodes
MAKEFILE=make/freebsd${X_OR_NOT}.mak
AUTHOR=		"Ullrich von Bassewitz" <uz@ibb.schwaben.com>

OPTIONS_DEFINE=	X11 DTR_OFF DOCS
OPTIONS_DEFAULT=X11
NO_OPTIONS_SORT=yes
DTR_OFF_DESC=	use dtr-off patch
X11_USE=	xorg=x11

FIXME=	areacode estic spunk

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
X_OR_NOT=-x
PLIST_SUB+=	WITHOUT_X="@comment "
PLIST_SUB+=	WITH_X=""
.else
NOX11_SUFFIX?=	-nox11
X_OR_NOT=
PLIST_SUB+=	WITHOUT_X=""
PLIST_SUB+=	WITH_X="@comment "
.endif

.if ${PORT_OPTIONS:MDTR_OFF}
EXTRA_PATCHES+=		${FILESDIR}/dtr-off.patch
.endif

pre-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
#	@${PATCH} -d ${PATCH_WRKSRC}/estic --forward --quiet -E -p0 --batch < ${WRKDIR}/estic.diff

do-configure:
.for i in ${FIXME}
	${REINPLACE_CMD} -e 's|CC|CXX|' -e 's|CFLAGS|CXXFLAGS|' \
		${WRKSRC}/${i}/make/freebsd.mak \
		${WRKSRC}/${i}/make/freebsd-x.mak
.endfor
	@cd ${WRKSRC}/spunk ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} dep
	@cd ${WRKSRC}/areacode ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} dep
	@cd ${ESTIC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} dep

do-build:
	cd ${WRKSRC}/spunk ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}
	cd ${WRKSRC}/areacode ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}
	cd ${ESTIC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}

do-install:
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${ESTIC}/xestic ${PBX_BIN}/
.else
	${INSTALL_PROGRAM} ${ESTIC}/estic ${PBX_BIN}/
.endif
	${INSTALL_DATA} ${ESTIC}/estic.res ${PBX_BIN}/
.if ${PORT_OPTIONS:MDOCS}
	@# estic doc says estic.res must be in bin path or current directory
	${MKDIR} ${PBX_DOC}
	${INSTALL_MAN} ${ESTIC}/estic.doc ${PBX_DOC}/
	@# estic.doc is not nroff format, & is in German, volunteers to create
	@# _and maintain_ nroff formatted English should contact ${AUTHOR}
	${INSTALL_MAN} ${FILESDIR}/README ${PBX_DOC}/
.endif
	@# ${FILESDIR}/README is not in nroff, but is a temporary document.
	${MKDIR} ${PBX_ETC} ${PBX_VAR}
	${INSTALL_DATA} ${ESTIC}/samples/estic.ini ${PBX_ETC}/estic.ini.generic_example
	${INSTALL_DATA} ${FILESDIR}/estic.ini ${PBX_ETC}/estic.ini.freebsd_example
	${INSTALL_DATA} ${ESTIC}/samples/alias.dat ${PBX_ETC}/aliases.example
	@# create config & debug so we can change mode to private
	${TOUCH} ${PBX_ETC}/config ${PBX_VAR}/debug
	${CHMOD} 600 ${PBX_VAR}/debug ${PBX_ETC}/config
	${CHMOD} 700 ${PBX_VAR} # estic will create ./1996.11 etc
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Suggestion, try:	make demo"

demo:
	@${ECHO_MSG} "If you want to try this under X-Windows, do this:"
	@${ECHO_MSG} " ${SETENV} SPUNK_LANGUAGE 001"
	@${ECHO_MSG} " ${SETENV} SPUNK_XFONT 8x13"
	@${ECHO_MSG} " cd ${PBX_ETC}"
	@${ECHO_MSG} " vi estic.ini"
	@${ECHO_MSG} " ${CHMOD} 666 /dev/cuaaX, or su"
	@${ECHO_MSG} " ${ESTIC}/xestic -display :0"
	@${ECHO_MSG} " (If you have no Istec 100[38] connected, append -n )"
	@${ECHO_MSG} " A BUGS & PROBLEMS section exists in ${FILESDIR}/README == man estic_freebsd"

# Ref. NO_CDROM= & NO_PACKAGE=
# It is not necessary to prevent inclusion of source or binary on FreeBSD
# CDROMs, # (despite the original German phraseology) as I (<jhs@freebsd.org>)
# have obtained a waiver.  See ${FILESDIR}/README for explanation.

.include <bsd.port.mk>
