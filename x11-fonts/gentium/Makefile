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
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=Gentium_102_L_tar&_sc=1&filename=/
DISTNAME=	ttf-sil-${PORTNAME}_${PORTVERSION}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium TrueType font collection

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ttf-sil-${PORTNAME}-${PORTVERSION:C@\.([[:digit:]]+)$@\1@}

PLIST_SUB=	FONTSDIR="${FONTSDIR}" \
		FONTNAME="${FONTNAME}"

SUB_LIST=	"FONTSDIR=${FONTSDIR}"
SUB_FILES=	pkg-message

#
# Local variables
#

FONTNAME=	${PORTNAME}
FONTSDIR?=	lib/X11/fonts/${FONTNAME}
FONTSTGT=	${PREFIX}/${FONTSDIR}

DOCSLIST=	FONTLOG GENTIUM-FAQ Gentium-Greek-Specimen.pdf \
		Gentium-RU-A3Proofs.pdf Gentium-RU-Specimen.pdf \
		OFL-FAQ QUOTES README

.SILENT:

#
# Install
#

do-install: install-fonts install-conf install-docs

install-fonts:
	${MKDIR} ${FONTSTGT}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSTGT}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${FONTSTGT}
	${INSTALL_DATA} ${WRKSRC}/OFL ${FONTSTGT}

install-conf:
	${MKDIR} ${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${WRKSRC}/local.conf \
		${PREFIX}/etc/fonts/conf.d/${FONTNAME}.conf

install-docs:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@for doc in ${DOCSLIST} ; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$doc ${DOCSDIR} ; \
	done
.endif

post-install:
	${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSTGT}
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

.include <bsd.port.mk>
