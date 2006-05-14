# New ports collection makefile for:	gsfonts
# Date created:		11 September 1997
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	gsfonts
PORTVERSION=	8.11
PORTREVISION=	2
CATEGORIES=	print x11-fonts
MASTER_SITES=	ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/fonts/ \
		${MASTER_SITE_TEX_CTAN:S/$/:CTAN/}
MASTER_SITE_SUBDIR=	support/ghostscript/fonts/:CTAN
DISTFILES=	${GS_FONTS_STD:S/$/:DEFAULT,CTAN/} ${GS_FONTS_OTHER:S/$/:DEFAULT,CTAN/}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fonts used by GNU Ghostscript (or X)

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR="${FONTSDIR}"

#
# Local variables
#

FONTSDIR?=	${PREFIX}/share/ghostscript/fonts
GS_FONTS_STD=	ghostscript-fonts-std-8.11.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-6.0.tar.gz

.SILENT:

post-patch:
	${CP} ${WRKSRC}/fonts/fonts.scale ${WRKSRC}/fonts/fonts.scale.urw
	${CP} ${FILESDIR}/fonts.scale ${WRKSRC}/fonts/fonts.scale
	${CP} ${FILESDIR}/fonts.scale ${WRKSRC}/fonts/fonts.dir
	${CP} ${FILESDIR}/Fontmap ${WRKSRC}/fonts/Fontmap

#
# Install
#

do-install: install-fonts install-docs display-message

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
	${INSTALL_DATA} ${WRKSRC}/fonts/fonts.scale.urw ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/Fontmap ${FONTSDIR}

install-docs:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/README.tweaks ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/TODO ${DOCSDIR}
.endif

display-message:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
