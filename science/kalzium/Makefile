PORTNAME=	kalzium
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	science education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Periodic table of elements for KDE
WWW=		https://www.kde.org/applications/education/kalzium

LICENSE=	GPLv2 LGPL20 GFDL
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/facile/facile.a:math/facile \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data
LIB_DEPENDS=	libAvogadroCore.so:science/avogadrolibs \
		libopenbabel.so:science/openbabel
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools gl \
		kde:6 ocaml:build pkgconfig qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	attica colorscheme completion config configwidgets \
		coreaddons crash doctools guiaddons i18n itemviews \
		jobwidgets kio newstuff plotting service sonnet textwidgets \
		unitconversion widgetsaddons xmlgui \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		5compat base declarative scxml svg
USE_XORG=	x11

PIE_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
