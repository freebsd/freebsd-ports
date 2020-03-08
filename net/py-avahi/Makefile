# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/py-avahi/Makefile,v 1.4 2007/07/31 18:24:13 ahze Exp $

PORTREVISION=	0
CATEGORIES=	net gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the Avahi mDNS system

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>0:databases/py-gdbm@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libavahi-client.so:net/avahi-app
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>0:databases/py-gdbm@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:devel/py-dbus@${PY_FLAVOR} \
		avahi-gtk>=0.7:net/avahi-gtk

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	python

USE_GNOME=	pygobject3 pygtk2 gtk30
USES=		python:2.7
USE_PYTHON=	flavors
MANPAGES=	avahi-bookmarks.1 avahi-discover.1

post-patch:
	@${REINPLACE_CMD} -e 's|@pkglibdir@|${DATADIR}|' \
		${WRKSRC}/avahi-python/avahi/ServiceTypeDatabase.py.in

pre-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} clean

post-build:
	@cd ${WRKSRC}/service-type-database && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@cd ${WRKSRC}/service-type-database && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} install
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})

.include "${MASTERDIR}/Makefile"
