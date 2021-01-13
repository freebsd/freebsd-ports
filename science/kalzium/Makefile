# $FreeBSD$

PORTNAME=	kalzium
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	science education kde kde-applications

PATCH_SITES=	https://invent.kde.org/education/kalzium/commit/
PATCHFILES=	2b9ebd85.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Periodic table of elements for KDE

LICENSE=	GPLv2 LGPL20 GFDL
LICENSE_COMB=	multi

LIB_DEPENDS=	libopenbabel.so:science/openbabel \
		libAvogadroCore.so:science/avogadrolibs
BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/facile/facile.a:math/facile \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl kde:5 \
		pkgconfig qt:5 tar:xz
USE_GL=		gl glew glu
USE_KDE=	auth archive attica bookmarks codecs completion config configwidgets \
		coreaddons crash doctools ecm emoticons guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets js kdelibs4support \
		khtml kio newstuff notifications parts plotting service solid \
		sonnet textwidgets unitconversion widgetsaddons windowsystem \
		xmlgui
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT=		concurrent core dbus declarative gui network opengl printsupport script svg \
		widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

CMF=		. compoundviewer compoundviewer/widgets src

OPTIONS_DEFINE=	DOCS

post-patch:
	${CP} ${WRKSRC}/cmake/modules/FindOpenBabel2.cmake \
		${WRKSRC}/cmake/modules/FindOpenBabel3.cmake
	${REINPLACE_CMD} -e 's|OPENBABEL2|OPENBABEL3|g;s|OpenBabel2|OpenBabel3|' \
		-e 's|openbabel-2.0|openbabel-3|;s|openbabel-2|openbabel-3|' \
		${WRKSRC}/cmake/modules/FindOpenBabel3.cmake
.for c in ${CMF}
	${REINPLACE_CMD} -e 's|OpenBabel2|OpenBabel3|;s|OPENBABEL2|OPENBABEL3|;s|OpenBabel3_|OPENBABEL3_|;s|OPENBABEL3_INCLUDE_DIRS|OPENBABEL3_INCLUDE_DIR|;s|OPENBABEL2_|OPENBABEL3_|' \
		${WRKSRC}/${c}/CMakeLists.txt
.endfor

.include <bsd.port.mk>
