# New ports collection makefile for:   HAL
# Date Created:			02 May 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/hal/Makefile,v 1.43 2008/03/22 19:31:15 marcus Exp $
#

PORTNAME=	hal
DISTVERSION=	0.5.11rc2
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Hardware Abstraction Layer for simplifying device access

LIB_DEPENDS=	polkit.2:${PORTSDIR}/sysutils/policykit \
		volume_id.0:${PORTSDIR}/devel/libvolume_id \
		ck-connector.0:${PORTSDIR}/sysutils/consolekit
RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:${PORTSDIR}/misc/pciids

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget intlhack ltverhack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-backend=freebsd \
		--disable-docbook-docs \
		--with-pci-ids=${LOCALBASE}/share/pciids \
		--disable-usb-ids \
		--without-libpci \
		--disable-usb \
		--disable-smbios \
		--disable-apm \
		--disable-pmu \
		--enable-policy-kit \
		--enable-console-kit \
		--with-socket-dir=/var/run/hald \
		--with-eject=/usr/sbin/cdcontrol \
		--with-pid-file=/var/run/hald/hald.pid \
		--with-deprecated-keys \
		--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"

#HALVERSION=	0.5.10
#SNAPVERSION=	20080218

USE_RC_SUBR=	hald
USE_GNOME_SUBR=	yes
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}
PLIST_SUB=	VERSION=${DISTVERSION}

RC_FILES=	hal.conf:${PREFIX}/etc/dbus-1/system.d
PLIST_FILES=	${PRIV_FILES:S|^|%%DATADIR%%/dist/|}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	RC_FILES="${RC_FILES}"

MAN1=		hal-disable-polling.1 hal-find-by-capability.1 \
		hal-find-by-property.1 hal-get-property.1 \
		hal-is-caller-locked-out.1 hal-is-caller-privileged.1 \
		hal-lock.1 hal-set-property.1 lshal.1
MAN8=		hald.8

OPTIONS=	FIXED_MOUNTPOINTS "use fixed mountpoints" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 505000
IGNORE=	not supported on FreeBSD prior to 5.5-RELEASE
.endif

.if (${ARCH}=="i386" || ${ARCH}=="amd64" || ${ARCH}=="ia64")
RUN_DEPENDS+=	dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

.if ${OSVERSION} <= 601100
NEEDS_MEDIA=	yes
PLIST_SUB+=	MEDIA=""
.else
PLIST_SUB+=	MEDIA="@comment "
.endif

.if defined(WITH_FIXED_MOUNTPOINTS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-tools_hal-storage-mount.c
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^scriptdir = /s|libdir|libexecdir|' \
		${WRKSRC}/tools/Makefile.in \
		${WRKSRC}/tools/freebsd/Makefile.in
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/hal/scripts|(libexecdir)/hal/scripts|' \
		${WRKSRC}/hald/Makefile.in
	@${REINPLACE_CMD} -e 's|user="0"|group="operator"|g' \
		${WRKSRC}/hal.conf.in

post-install:
	${MKDIR} ${DATADIR}/dist
	${INSTALL_DATA} ${WRKSRC}/hal.conf ${DATADIR}/dist
	${MKDIR} ${PREFIX}/share/hal/fdi/policy/10osvendor
	${INSTALL_DATA} ${FILESDIR}/10-mouse-sysmouse.fdi \
	    	${PREFIX}/share/hal/fdi/policy/10osvendor
	@${SETENV} PKG_PREFIX=${PREFIX} PACKAGE_BUILDING=${PACKAGE_BUILDING} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(PACKAGE_BUILDING) && defined(NEEDS_MEDIA)
	${MKDIR} /media
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/hald/freebsd/README \
		${DOCSDIR}/README.freebsd
.endif

.include <bsd.port.post.mk>
