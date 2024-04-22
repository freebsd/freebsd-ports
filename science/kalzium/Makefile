PORTNAME=	kalzium
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	science education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Periodic table of elements for KDE
WWW=		https://www.kde.org/applications/education/kalzium

LICENSE=	GPLv2 LGPL20 GFDL
LICENSE_COMB=	multi

LIB_DEPENDS=	libopenbabel.so:science/openbabel \
		libAvogadroCore.so:science/avogadrolibs
BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/facile/facile.a:math/facile \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl kde:5 \
		pkgconfig qt:5 tar:xz xorg
USE_GL=		gl glew glu
USE_KDE=	auth archive attica bookmarks codecs completion config configwidgets \
		coreaddons crash doctools emoticons guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets js kdelibs4support \
		khtml kio newstuff notifications parts plotting service solid \
		sonnet textwidgets unitconversion widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT=		concurrent core dbus declarative gui network opengl printsupport script svg \
		widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
