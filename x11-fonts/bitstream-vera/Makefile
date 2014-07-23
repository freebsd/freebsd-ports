# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-fonts/bitstream-vera/Makefile,v 1.2 2005/10/14 20:39:59 adamw Exp $

PORTNAME=	bitstream-vera
PORTVERSION=	1.10
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/ttf-${PORTNAME}/1.10
DISTNAME=	ttf-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Bitstream Vera TrueType font collection

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

#
# Local variables
#

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	${SED} 's|%%FONTSDIR%%|${FONTSDIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

do-install: install-fonts install-docs

install-fonts:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.TXT ${STAGEDIR}${FONTSDIR}

install-docs:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASENOTES.TXT ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
