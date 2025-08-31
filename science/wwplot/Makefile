PORTNAME=	wwplot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plotting tool for experimental physics classes
WWW=		https://github.com/wwmm/wwplot

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS} \
		qt6-base>0:devel/qt6-base
PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		desktop-file-utils gettext meson python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	wwmm

SHEBANG_FILES=	wwplot.in

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} "s|find_installation('python3',|find_installation('python${PYTHON_VER}',|" ${WRKSRC}/meson.build

.include <bsd.port.mk>
