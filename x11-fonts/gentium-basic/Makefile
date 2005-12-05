# New ports collection makefile for:	Gentium Font Family
# Date created:		March 31 2004
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#
# This port is shamelessly copied from Joe Marcus Clarke's bitstream-vera
# port.

PORTNAME=	gentium
PORTVERSION=	1.0.2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=Gentium_102_L_tar&_sc=1&filename=/
DISTNAME=	ttf-sil-${PORTNAME}_${PORTVERSION}

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Gentium TrueType font collection

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ttf-sil-${PORTNAME}-${PORTVERSION:C@\.([[:digit:]]+)$@\1@}

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}" \
		FONTNAME=${FONTNAME}

SUB_LIST=	"FONTSDIR=${FONTSDIR}"
SUB_FILES=	pkg-message

#
# Local variables
#

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}

DOCSLIST=	FONTLOG GENTIUM-FAQ Gentium-Greek-Specimen.pdf \
		Gentium-RU-A3Proofs.pdf Gentium-RU-Specimen.pdf \
		OFL-FAQ QUOTES README

.SILENT:

#
# Install
#

do-install: install-fonts install-conf install-docs

install-fonts:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/OFL ${FONTSDIR}

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
