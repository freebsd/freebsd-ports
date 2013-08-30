# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/py-avahi/Makefile,v 1.4 2007/07/31 18:24:13 ahze Exp $
PORTREVISION=	5
CATEGORIES=	net gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the Avahi mDNS system

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>0:${PORTSDIR}/databases/py-gdbm \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus
LIB_DEPENDS=	avahi-client.3:${PORTSDIR}/net/avahi-app
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>0:${PORTSDIR}/databases/py-gdbm \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus

BROKEN=		fails to install

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	python

USE_GNOME=	gnomehack pygtk2
USE_PYTHON=	yes
MAN1=		avahi-bookmarks.1 avahi-discover.1

post-patch:
	@${REINPLACE_CMD} -e 's|@pkglibdir@|${DATADIR}|' \
	    	${WRKSRC}/avahi-python/avahi/ServiceTypeDatabase.py.in

pre-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
	    	Makefile ${MAKE_ARGS} clean

post-build:
	@cd ${WRKSRC}/service-type-database && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/service-type-database/service-types.db ${DATADIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHONPREFIX_SITELIBDIR}/avahi
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHONPREFIX_SITELIBDIR}/avahi

.include "${MASTERDIR}/Makefile"
