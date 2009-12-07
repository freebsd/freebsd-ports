# New ports collection makefile for:	Gentium Font Family
# Date created:		March 31 2004
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#
# This port is shamelessly copied from Joe Marcus Clarke's bitstream-vera
# port.

PORTNAME=	gentium-basic
PORTVERSION=	1.1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?site_id=nrsi&format=file&media_id=GentiumBasic_${PORTVERSION:C@\.@@g}_tar&filename=/
DISTNAME=	ttf-sil-${PORTNAME}_${PORTVERSION:C@\.[[:digit:]]+$@@}.orig

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Gentium Basic and Gentium Book Basic TrueType fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ttf-sil-${PORTNAME}-${PORTVERSION:C@\.[[:digit:]]+$@@}

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

DOCSLIST=	FONTLOG.txt GENTIUM-FAQ.txt OFL-FAQ.txt

.SILENT:

#
# Install
#

do-install: install-fonts install-docs

install-fonts:
	${MKDIR} ${FONTSTGT}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSTGT}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${FONTSTGT}
	${INSTALL_DATA} ${WRKSRC}/OFL.txt ${FONTSTGT}

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
