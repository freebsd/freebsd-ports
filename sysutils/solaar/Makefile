# $FreeBSD$

PORTNAME=	solaar
PORTVERSION=	g20170327
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Device manager for the Logitech Unifying Receiver

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# libhidapi.so is only loaded at runtime via ctypes (dlopen)
RUN_DEPENDS=	${LOCALBASE}/lib/libhidapi.so:comms/hidapi

USES=	python
USE_PYTHON=	distutils autoplist concurrent optsuffix

USE_GITHUB=	yes
GH_ACCOUNT=	pwr
GH_PROJECT=	Solaar
# The latest release is from 2013 and there is not going to be a new
# release for now:
# https://github.com/pwr/Solaar/issues/288
# https://github.com/pwr/Solaar/issues/296
GH_TAGNAME=	53ec751

NO_ARCH=	yes

OPTIONS_DEFINE=	GUI
GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${FLAVOR}

post-patch:
	@${CP} ${FILESDIR}/hidapi.py ${WRKSRC}/lib/hidapi/udev.py
	@${REINPLACE_CMD} -e '/pyudev/d' \
		-e 's|python-gi|${PYTHON_PKGNAMEPREFIX}gobject3|' \
		${WRKSRC}/lib/solaar/gtk.py
	@${REINPLACE_CMD} 's|receiver\.path\.split.*|receiver.path)|' \
		${WRKSRC}/lib/logitech_receiver/listener.py
	@${REINPLACE_CMD} 's|[[:<:]]cmd[[:>:]]|action|' \
		${WRKSRC}/lib/solaar/cli/__init__.py

.include <bsd.port.mk>
