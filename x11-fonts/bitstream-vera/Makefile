# New ports collection makefile for:	Bitstream Vera Font Family
# Date created:		February 18 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitstream-vera
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@freebsd.org
COMMENT=	Bitstream Vera collection of 10 TrueType fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

NO_CDROM=	"Restrictive license - may not distribute"
NO_PACKAGE=	"Restrictive license - may not distribute"

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

#
# Local variables
#

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}

.SILENT:

#
# Post-patch
#

post-patch:
	${SED} 's|%%FONTSDIR%%|${FONTSDIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

#
# Install
#

do-install: install-fonts install-conf install-docs

install-fonts:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.TXT ${FONTSDIR}

install-conf:
	${MKDIR} ${PREFIX}/etc/fonts
	${INSTALL_DATA} ${WRKSRC}/local.conf ${PREFIX}/etc/fonts

install-docs:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Bitstream_Vera_Fonts_README.html ${DOCSDIR}
.endif

#
# Post-install
#

post-install: run-fc-cache display-message

run-fc-cache:
	${ECHO_MSG} "===> Running fc-cache"
	-${X11BASE}/bin/fc-cache -f -v

display-message:
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

.include <bsd.port.mk>
