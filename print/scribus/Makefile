# Created by: ijliao
# $Carpetsmoker: ports/print/scribus/Makefile,v 1.2 2007/09/24 08:06:52 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	print editors
MASTER_SITES=	SF \
		http://www.scribus.net/downloads/${PORTVERSION}/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png15:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		cups.2:${PORTSDIR}/print/cups-client \
		freetype.9:${PORTSDIR}/print/freetype2 \
		podofo.0:${PORTSDIR}/graphics/podofo \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		aspell.16:${PORTSDIR}/textproc/aspell \
		cairo.2:${PORTSDIR}/graphics/cairo \
		hyphen:${PORTSDIR}/textproc/hyphen \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info

NO_LATEST_LINK=	yes
USE_XZ=		yes
USE_QT4=	gui linguist_build moc_build qmake_build rcc_build uic_build xml network
USE_GNOME=	desktopfileutils libartlgpl2 libxml2 pkgconfig
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/Scribus

MAN1=		scribus.1
MANLANG=	"" pl de
MANCOMPRESSED=	no

post-install:
	${LN} ${DATADIR}/icons/scribus.png ${PREFIX}/share/pixmaps/
	-update-desktop-database
	-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
