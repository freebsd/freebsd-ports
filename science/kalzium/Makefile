# $FreeBSD$

PORTNAME=	kalzium
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	science kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Periodic table of elements for KDE 4

LIB_DEPENDS=	libopenbabel.so:science/openbabel \
		libavogadro.so:science/avogadro
BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/facile/facile.a:math/facile \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data

USES=		cmake:outsource gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	auth archive bookmarks codecs completion config configwidgets \
		coreaddons crash doctools ecm emoticons guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets js kdelibs4support \
		khtml kio newstuff notifications parts plotting service solid \
		sonnet textwidgets unitconversion widgetsaddons windowsystem \
		xmlgui
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT=		core dbus gui network opengl printsupport qml quick script svg \
		widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

.include <bsd.port.mk>
