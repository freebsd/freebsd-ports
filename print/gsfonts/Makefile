# New ports collection makefile for:	gsfonts
# Date created:		11 September 1997
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	gsfonts
PORTVERSION=	8.11
CATEGORIES=	print x11-fonts
MASTER_SITES=	ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/fonts/
DISTFILES=	${GS_FONTS_STD} ${GS_FONTS_OTHER}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fonts used by GNU Ghostscript (or X)

BUILD_DEPENDS=	type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

#
# Local variables
#

FONTSDIR?=	${PREFIX}/share/ghostscript/fonts
GS_FONTS_STD=	ghostscript-fonts-std-8.11.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-6.0.tar.gz

.SILENT:

post-patch:
	${SED} 's|%%FONTSDIR%%|${FONTSDIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

#

#
# Install
#

do-install: install-foundries install-fonts install-docs

install-foundries:
	${CAT} ${WRKSRC}/fonts/fonts.scale | \
	${SED} -e 's|-URW-|-Adobe-|g' | \
	${SED} -e 's|-urw-|-adobe-|g' > \
	${WRKSRC}/fonts/fonts.scale
	${CAT} ${WRKSRC}/fonts/fonts.dir | \
	${SED} -e 's|-URW-|-Adobe-|g' | \
	${SED} -e 's|-urw-|-adobe-|g' > \
	${WRKSRC}/fonts/fonts.dir

install-fonts:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/COPYING ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.afm ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.gsf ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.pfa ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.pfb ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.pfm ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/fonts.dir ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/fonts.scale ${FONTSDIR}
	(cd ${FONTSDIR}; ${LOCALBASE}/bin/type1inst -nox -nolog -q)

install-docs:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/README.tweaks ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/TODO ${DOCSDIR}
.endif

.include <bsd.port.mk>
