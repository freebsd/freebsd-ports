# $FreeBSD$

PORTNAME=	solaar
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Device manager for the Logitech Unifying Receiver

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# libhidapi.so is only loaded at runtime via ctypes (dlopen)
RUN_DEPENDS=	${LOCALBASE}/lib/libhidapi.so:comms/hidapi

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pwr-Solaar
GH_PROJECT=	Solaar
USE_PYTHON=	autoplist concurrent distutils optsuffix

NO_ARCH=	yes

OPTIONS_DEFINE=	GUI

GUI_USES=	gnome
GUI_USE=	GNOME=pygobject3:run

post-patch:
	@${CP} ${FILESDIR}/hidapi.py ${WRKSRC}/lib/hidapi/udev.py
	@${REINPLACE_CMD} -e '/pyudev/d' \
		-e 's|python-gi|${PYTHON_PKGNAMEPREFIX}gobject3|' \
		${WRKSRC}/lib/solaar/gtk.py
	@${REINPLACE_CMD} 's|receiver\.path\.split.*|receiver.path)|' \
		${WRKSRC}/lib/logitech_receiver/listener.py
	@${REINPLACE_CMD} 's|[[:<:]]cmd[[:>:]]|action|' \
		${WRKSRC}/lib/solaar/cli/__init__.py

post-build:
	${AWK} -f ${FILESDIR}/devd-solaar.awk \
		${WRKSRC}/rules.d/42-logitech-unify-permissions.rules \
		> ${WRKDIR}/solaar.conf.sample

post-install:
	${INSTALL_DATA} ${WRKDIR}/solaar.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
