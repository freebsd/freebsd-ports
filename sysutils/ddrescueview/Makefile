PORTNAME=	ddrescueview
PORTVERSION=	0.4.5
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	https://sourceforge.net/projects/${PORTNAME}/files/Test%20builds/v${PORTVERSION}/
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Graphical viewer for GNU ddrescue mapfiles
WWW=		https://sourceforge.net/projects/ddrescueview/

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64 i386

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

USES=		desktop-file-utils dos2unix fpc gnome lazarus:flavors tar:xz xorg
DOS2UNIX_REGEX=	.*\.([txt]|pas|lpi|lpr|txt)
USE_GNOME_gtk2=	cairo gdkpixbuf glib20 pango
USE_GNOME+=	${USE_GNOME_${FLAVOR}}
USE_XORG=	x11

LAZARUS_PROJECT_FILES=	source/ddrescueview.lpi
LAZARUS_PROJECT_FILES+=	source/ddrescueview.lpr
LAZBUILD_ARGS=		-d

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/resources/linux/man/man1/ddrescueview.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
.for i in 16 22 24 32 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/
	${INSTALL_DATA} ${WRKSRC}/resources/linux/icons/hicolor/${i}x${i}/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/linux/applications/ddrescueview.desktop \
		${STAGEDIR}${PREFIX}/share/applications

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changelog.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
