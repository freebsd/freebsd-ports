# New ports collection makefile for:	Gentium Font Family
# Date created:		March 31 2004
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#
# This port is shamelessly copied from Joe Marcus Clarke's bitstream-vera
# port.
#
# A note about MASTER_SITES.  The bsd.port.mk system, expects (not
# unreasonably) that the name of the distfile being fetched should be
# the last component of the URL it passes to fetch(1).  Unfortunately,
# in this case the master site uses some sort of fancy content
# management system and the URL required to download the distfile is
# strictly:
#
# http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=Gentium_101_LT&_sc=1
#
# No mention of the distfile there.  Hack around the problem by adding
# a dummy argument to the CGI arg list, which the site ignores, but
# that serves to placate bsd.ports.mk

PORTNAME=	gentium
PORTVERSION=	1.0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=Gentium_101_LT&_sc=1&dummy=/
DISTNAME=	fonts-ttf-${PORTNAME}-${PORTVERSION}

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Gentium TrueType font collection

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_CDROM=	License forbids commercial distribution without permission
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}" \
		FONTNAME=${FONTNAME}

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

#
# Local variables
#

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}

DOCSLIST=	CHANGELOG FAQ Gentium-Greek-Specimen.pdf \
		Gentium-RU-A3Proofs.pdf Gentium-RU-Specimen.pdf \
		HISTORY INSTALL ISSUES QUOTES README THANKS

.SILENT:

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
	${INSTALL_DATA} ${WRKSRC}/COPYING ${FONTSDIR}

install-conf:
	${MKDIR} ${PREFIX}/etc/fonts
	if [ ! -f ${PREFIX}/etc/fonts/local.conf ]; then \
	    ${INSTALL_DATA} ${WRKSRC}/local.conf ${PREFIX}/etc/fonts ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/local.conf \
		${PREFIX}/etc/fonts/local.conf-${FONTNAME}

install-docs:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@for doc in ${DOCSLIST} ; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$doc ${DOCSDIR} ; \
	done
.endif

post-install:
	${ECHO_MSG} "===> Running fc-cache"
	-${X11BASE}/bin/fc-cache -f -v ${FONTSDIR}
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

.include <bsd.port.mk>
