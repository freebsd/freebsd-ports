PORTNAME=	udiskie
DISTVERSION=	2.7.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Removable disk automounter using the UDisks2 D-Bus API
WWW=		https://github.com/coldfix/udiskie

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygobject>0:devel/py-pygobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		bsdisks:sysutils/bsdisks

USES=		gnome python
USE_GNOME=	gtk30:run introspection:run
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	NLS NOTIFY
OPTIONS_DEFAULT=	NLS NOTIFY

NOTIFY_DESC=	Desktop notifications via libnotify

NLS_USES=	gettext-tools
NOTIFY_RUN_DEPENDS=	${LOCALBASE}/lib/girepository-1.0/Notify-0.7.typelib:devel/libnotify

# setup.py builds a catalog for every lang/*.po it finds.
post-patch-NLS-off:
	${RM} ${WRKSRC}/lang/*.po

.include <bsd.port.mk>
