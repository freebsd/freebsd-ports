# ports collection makefile for:	estic
# Date created:				21 Sep 1996
# Whom:					Julian Stacey <jhs@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		estic
PORTVERSION=		1.40
CATEGORIES=		misc
MASTER_SITES=		ftp://linux01.gwdg.de/pub/isdn/estic/old-versions/v1.40/
DISTNAME=		estic-${PORTVERSION}-sources

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Controller for ISDN TK-Anlage (PBX) made by Istec

USE_XLIB=		yes
USE_ZIP=		yes
NO_WRKSUBDIR=		yes

#			maybe one of them depends on the vga font from pcemu ?
X_OR_NOT=-x#		With X Window System,		Runs OK
#X_OR_NOT=#		Without X Window System,	Compile fails
AUTHOR=			"Ullrich von Bassewitz" <uz@ibb.schwaben.com>

# Personal Preferences, Where to install.
PBX_VAR=${PREFIX}/var/log/pbx
PBX_ETC=${PREFIX}/etc/pbx
PBX_MAN=${MANPREFIX}/man/man1
PBX_BIN=${PREFIX}/bin
PBX_DOC=${DOCSDIR}
ESTIC=${WRKSRC}/estic
MAKE_E=	make X11BASE=${X11BASE} -f make/freebsd${X_OR_NOT}.mak

do-configure:
	@cd ${WRKSRC}/spunk ; ${MAKE_E} dep
	@cd ${ESTIC} ; ${MAKE_E} dep

do-build:
	@# If you don't want ResourceEditor you can `cd spunk ; ${MAKE_E} lib`
	cd ${WRKSRC}/spunk ; ${MAKE_E}
	cd ${ESTIC} ; ${MAKE_E}

do-install:
	${INSTALL_PROGRAM} ${ESTIC}/xestic ${PBX_BIN}/
	${INSTALL_DATA} ${ESTIC}/estic.res ${PBX_BIN}/
	@# estic doc says estic.res must be in bin path or current directory
	@${MKDIR} ${PBX_DOC}
	${INSTALL_MAN} ${ESTIC}/estic.doc ${PBX_DOC}
	@# estic.doc is not nroff format, & is in German, volunteers to create
	@# _and maintain_ nroff formatted English should contact ${AUTHOR}
	${INSTALL_MAN} ${FILESDIR}/README ${PBX_DOC}
	@# ${FILESDIR}/README is not in nroff, but is a temporary document.
	@${MKDIR} ${PBX_ETC} ${PBX_VAR}
	${INSTALL_DATA} ${ESTIC}/estic.ini ${PBX_ETC}/estic.ini.generic_example
	${INSTALL_DATA} ${FILESDIR}/estic.ini ${PBX_ETC}/estic.ini.freebsd_example
	${INSTALL_DATA} ${ESTIC}/alias.dat ${PBX_ETC}/aliases.example
	@# create config & debug so we can change mode to private
	@touch ${PBX_ETC}/config ${PBX_VAR}/debug
	${CHMOD} 600 ${PBX_VAR}/debug ${PBX_ETC}/config
	${CHMOD} 700 ${PBX_VAR} # estic will create ./1996.11 etc

post-install:
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
