# New ports collection makefile for:   py-avahi
# Date Created:			06 May 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	net gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the Avahi mDNS system

BUILD_DEPENDS=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/gdbm.so:${PORTSDIR}/databases/py-gdbm \
		${PYTHON_SITELIBDIR}/dbus.pth:${PORTSDIR}/devel/py-dbus
LIB_DEPENDS=	avahi-client.3:${PORTSDIR}/net/avahi
RUN_DEPENDS=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/gdbm.so:${PORTSDIR}/databases/py-gdbm \
		${PYTHON_SITELIBDIR}/dbus.pth:${PORTSDIR}/devel/py-dbus

MASTERDIR=	${.CURDIR}/../avahi
BUILD_WRKSRC=	${WRKSRC}/avahi-python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	yes

USE_GNOME=	gnomehack gnometarget pygtk2
USE_PYTHON=	yes
CONFIGURE_ARGS=	--enable-python \
		--disable-mono \
		--disable-monodoc \
		--disable-gtk \
		--disable-qt3 \
		--disable-qt4 \
		--localstatedir=/var \
		--disable-doxygen-docs \
		--disable-xml-docs \
		--disable-doxygen-dot \
		--localstatedir=/var \
		--with-dbus-system-address=unix:path=/var/run/dbus/dbus.pipe \
		--with-distro=freebsd

MAN1=		avahi-bookmarks.1 avahi-discover.1

post-build:
	@cd ${WRKSRC}/service-type-database && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/service-type-database/service-types.db ${DATADIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
.for mf in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${mf} ${MAN1PREFIX}/man/man1
.endfor

.include "${MASTERDIR}/Makefile"
