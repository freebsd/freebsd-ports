# FreeBSD ports collection makefile for:	estic
# Version required:				1.40
# Date created:					21 Sep 1996
# Whom:						Julian Stacey <jhs@freebsd.org>
#
# $Id: Makefile,v 1.3 1998/11/29 12:43:11 asami Exp $
#

DISTNAME=		estic-1.40-sources
PKGNAME=		estic-1.40
CATEGORIES=		misc
MASTER_SITES=		ftp://linux01.gwdg.de/pub/isdn/estic/  \
			ftp://ftp.franken.de/pub/isdn4linux/estic/  \
			http://www.fast.de/~uli/isdn/estic/
EXTRACT_SUFX=		.zip

MAINTAINER=		jhs@FreeBSD.org

BUILD_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip

USE_XLIB=		yes
EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=		yes

#			maybe one of them depends on the vga font from pcemu ?
X_OR_NOT=-x#		With X Window System,		Runs OK
#X_OR_NOT=#		Without X Window System,	Compile fails
AUTHOR=			"Ullrich von Bassewitz" <uz@ibb.schwaben.com>

# Personal Preferences, Where to install.
PBX_VAR=${PREFIX}/var/log/pbx
PBX_ETC=${PREFIX}/etc/pbx
PBX_MAN=${PREFIX}/man/man1
PBX_BIN=${PREFIX}/bin
PBX_DOC=${PREFIX}/share/doc/estic
ESTIC=${WRKSRC}/estic
MAKE_E= make X11BASE=${X11BASE} -f make/freebsd${X_OR_NOT}.mak

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
	@# files/README is not in nroff, but is a temporary document.
	@${MKDIR} ${PBX_ETC} ${PBX_VAR}
	${INSTALL_DATA} ${ESTIC}/estic.ini ${PBX_ETC}/estic.ini.generic_example
	${INSTALL_DATA} ${FILESDIR}/estic.ini ${PBX_ETC}/estic.ini.freebsd_example
	${INSTALL_DATA} ${ESTIC}/alias.dat ${PBX_ETC}/aliases.example
	@# create config & debug so we can change mode to private
	@touch ${PBX_ETC}/config ${PBX_VAR}/debug
	chmod 600 ${PBX_VAR}/debug ${PBX_ETC}/config
	chmod 700 ${PBX_VAR} # estic will create ./1996.11 etc

post-install:
	@echo ""
	@echo " Suggestion, try:	make demo"

demo:
	@echo "If you want to try this under X-Windows, do this:"
	@echo " setenv SPUNK_LANGUAGE 001"
	@echo " setenv SPUNK_XFONT 8x13"
	@echo " cd ${PBX_ETC}"
	@echo " vi estic.ini"
	@echo " chmod 666 /dev/cuaaX, or su"
	@echo " ${ESTIC}/xestic -display :0"
	@echo " (If you have no Istec 100[38] connected, append -n )"
	@echo " A BUGS & PROBLEMS section exists in files/README == man estic_freebsd"

# Ref. NO_CDROM= & NO_PACKAGE=
# It is not necessary to prevent inclusion of source or binary on FreeBSD
# CDROMs, # (despite the original German phraseology) as I (<jhs@freebsd.org>)
# have obtained a waiver.  See files/README for explanation.

.include <bsd.port.mk>
