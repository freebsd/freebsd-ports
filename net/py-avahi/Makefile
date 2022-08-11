PORTREVISION=	0
CATEGORIES=	net gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the Avahi mDNS system

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>0:databases/py-gdbm@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libavahi-client.so:net/avahi-app
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>0:databases/py-gdbm@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:devel/py-dbus@${PY_FLAVOR} \
		avahi-gtk3>=0.7:net/avahi-gtk3

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	python

USE_GNOME=	pygobject3 gtk30
USES=		python:3.5+
USE_PYTHON=	flavors py3kplist
MANPAGES=	avahi-bookmarks.1

# See https://github.com/lathiat/avahi/issues/277
post-extract:
	${CP} ${FILESDIR}/build-db ${WRKSRC}/service-type-database

post-patch:
	@${REINPLACE_CMD} -e 's|@pkglibdatadir@|${DATADIR}|' \
		${WRKSRC}/avahi-python/avahi/ServiceTypeDatabase.py.in

do-build:
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC}
	@${DO_MAKE_BUILD} -C ${WRKSRC}/service-type-database

do-install:
	@(cd ${BUILD_WRKSRC}; ${MAKE_CMD} ${MAKE_ARGS} install-strip)
	@(cd ${WRKSRC}/service-type-database; ${MAKE_CMD} ${MAKE_ARGS} install)

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})

.include "${MASTERDIR}/Makefile"
