# New ports collection makefile for:	avahi
# Date created:		18 November 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avahi
PORTVERSION=	0.6
CATEGORIES=	net dns
MASTER_SITES=	http://www.freedesktop.org/~lennart/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Service discovery on a local network

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2 \
		daemon.2:${PORTSDIR}/devel/libdaemon \
		dbus-1.1:${PORTSDIR}/devel/dbus \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_GNOME=	gnomehack ltverhack glib20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-distro=freebsd \
		--disable-gtk \
		--disable-qt3 \
		--disable-qt4 \
		--disable-python \
		--disable-mono \
		--disable-monodoc \
		--disable-doxygen-doc \
		--disable-doxygen-dot
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_RC_SUBR=	yes
FILES_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAN1=	avahi-browse-domains.1 avahi-browse.1 avahi-publish-address.1 \
	avahi-publish-service.1 avahi-publish.1 avahi-resolve-address.1 \
	avahi-resolve-host-name.1 avahi-resolve.1
MAN5=	avahi-daemon.conf.5 avahi.service.5
MAN8=	avahi-daemon.8 avahi-dnsconfd.8 avahi-dnsconfd.action.8

post-configure:
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/avahi-daemon.sh > ${WRKDIR}/avahi-daemon.sh
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/avahi-dnsconfd.sh > ${WRKDIR}/avahi-dnsconfd.sh

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/avahi-daemon.sh ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKDIR}/avahi-dnsconfd.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
