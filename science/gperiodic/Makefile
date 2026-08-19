PORTNAME=	gperiodic
DISTVERSION=	3.0.3
PORTREVISION=	3
CATEGORIES=	science education
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Graphical application for browsing the periodic table
WWW=		https://sourceforge.net/projects/gperiodic/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk20

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

LANGS=		be cs da de es fi fr gl is it ms pl pt ru sv tr uk zh_CN

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} `pkg-config --cflags --libs gtk+-2.0` \
		gperiodic.c -o gperiodic

do-build-NLS-on:
.for lang in ${LANGS}
	cd ${WRKSRC}/po && msgfmt -f -v -o ${lang}.mo ${lang}.po
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gperiodic ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/icons && ${INSTALL_DATA} gperiodic-crystal.png gperiodic.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-install-NLS-on:
.for lang in ${LANGS}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor

.include <bsd.port.mk>
