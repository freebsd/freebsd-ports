PORTNAME=	drkonqi
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Crash handler for KDE software

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygdbmi>=0:devel/py-pygdbmi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=0:devel/py-sentry-sdk@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygdbmi>=0:devel/py-pygdbmi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=0:devel/py-sentry-sdk@${PY_FLAVOR}

USES=		cmake gettext gl kde:6 pkgconfig python qt:6 tar:xz xorg
USE_KDE=	completion config coreaddons crash i18n idletime itemmodels \
		jobwidgets kcmutils kio kirigami2 notifications service \
		statusnotifieritem syntaxhighlighting userfeedback wallet \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11
USE_GL=		gl opengl
CMAKE_OFF=	WITH_PYTHON_VENDORING

.include <bsd.port.mk>
