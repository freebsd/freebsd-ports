PORTNAME=	xca
PORTVERSION=	2.9.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/chris2511/xca/releases/download/RELEASE.${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Graphical certification authority
WWW=		https://hohnstaedt.de/xca

LICENSE=	BSD-3-Clause
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

FLAVORS=		qt6 qt5
FLAVOR?=		${FLAVORS:[1]}
FLAVORS_SUB=		yes
qt5_PKGNAMESUFFIX=
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_PKGNAMESUFFIX=	-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}

USES=		cmake compiler:c++17-lang desktop-file-utils localbase \
		pkgconfig shared-mime-info ssl

.if ${FLAVOR} == qt5
DEPRECATED=		Depends on unsupported Qt 5
EXPIRATION_DATE=	2027-01-01

USES+=		qt:5
USE_QT=		core gui help qmake sql widgets buildtools:build linguist:build \
		testlib:build
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
