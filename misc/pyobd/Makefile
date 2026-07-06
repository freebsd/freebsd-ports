PORTNAME=	pyobd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19
CATEGORIES=	misc
#MASTER_SITES=	http://www.obdtester.com/download/
#DISTNAME=	pyobd_${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBD-II compliant car diagnostic tool
WWW=		http://www.obdtester.com/pyobd \
		https://github.com/barracuda-fsh/pyobd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=10.4.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.23:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.4.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.20.1:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.5:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=3.2.1:www/py-tornado@${PY_FLAVOR}

USES=		dos2unix gnome python shebangfix
USE_PYTHON=	autoplist pep517
USE_WX=		3.2

USE_GITHUB=	yes
GH_ACCOUNT=	barracuda-fsh

SHEBANG_FILES=	pyobd.py

WX_COMPS=	python

NO_ARCH=	yes

PLIST_FILES=	bin/pyobd \
		share/applications/pyobd.desktop \
		share/icons/hicolor/32x32/apps/pyobd.png \
		%%PYTHON_SITELIBDIR%%/pyobd.ico

post-build:
	@${PYTHON_CMD} -c "from PIL import Image; Image.open('${WRKSRC}/${PORTNAME}.gif').save('${WRKSRC}/${PORTNAME}.png')"

post-install:
	@(${ECHO_CMD} "#!/bin/sh"; \
	  ${ECHO_CMD} "exec ${PYTHON_CMD} -m pyobd \"\$$@\"") > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ico ${STAGEDIR}${PYTHON_SITELIBDIR}/

.include <bsd.port.mk>
