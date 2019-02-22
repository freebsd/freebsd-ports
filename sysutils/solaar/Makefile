# $FreeBSD$

PORTNAME=	solaar
# The latest release is from 2013 and there is not going to be a new
# release for now:
# https://github.com/pwr/Solaar/issues/288
# https://github.com/pwr/Solaar/issues/296
DISTVERSION=	0.9.2-259
DISTVERSIONSUFFIX=	-gc07c115
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Device manager for the Logitech Unifying Receiver

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# libhidapi.so is only loaded at runtime via ctypes (dlopen)
RUN_DEPENDS=	${LOCALBASE}/lib/libhidapi.so:comms/hidapi

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pwr
GH_PROJECT=	Solaar
USE_PYTHON=	distutils autoplist concurrent optsuffix

NO_ARCH=	yes

OPTIONS_DEFINE=	GUI
GUI_USES=	gnome
GUI_USE=	gnome=pygobject3:run

post-patch:
	@${CP} ${FILESDIR}/hidapi.py ${WRKSRC}/lib/hidapi/udev.py
	@${REINPLACE_CMD} -e '/pyudev/d' \
		-e 's|python-gi|${PYTHON_PKGNAMEPREFIX}gobject3|' \
		${WRKSRC}/lib/solaar/gtk.py
	@${REINPLACE_CMD} 's|receiver\.path\.split.*|receiver.path)|' \
		${WRKSRC}/lib/logitech_receiver/listener.py
	@${REINPLACE_CMD} 's|[[:<:]]cmd[[:>:]]|action|' \
		${WRKSRC}/lib/solaar/cli/__init__.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/devd-solaar.conf \
		${STAGEDIR}${PREFIX}/etc/devd/solaar.conf.sample

.include <bsd.port.mk>
