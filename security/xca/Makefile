PORTNAME=	xca
PORTVERSION=	2.7.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/xca/releases/download/RELEASE.${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Graphical certification authority
WWW=		https://hohnstaedt.de/xca

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

FLAVORS=		qt5 qt6
FLAVOR?=		${FLAVORS:[1]}
FLAVORS_SUB=		yes
qt5_PKGNAMESUFFIX=
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_PKGNAMESUFFIX=	-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}

USES=		cmake compiler:c++17-lang desktop-file-utils localbase \
		pkgconfig shared-mime-info ssl
GH_ACCOUNT=	chris2511
USE_LOCALE=	en_US.UTF-8

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_QT=		buildtools:build core gui help linguist:build qmake sql \
		testlib:build widgets
CMAKE_ARGS=	-DQTFIXEDVERSION:STRING=Qt5
.else
USES+=		gl qt:6
USE_GL=		opengl
USE_QT=		base sqldriver-sqlite tools
CMAKE_ARGS=	-DQTFIXEDVERSION:STRING=Qt6
.endif

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

.include <bsd.port.mk>
