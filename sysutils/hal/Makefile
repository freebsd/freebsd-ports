# New ports collection makefile for:   HAL
# Date Created:			02 May 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/hal/Makefile,v 1.26 2006/10/13 10:00:57 ahze Exp $
#

PORTNAME=	hal
PORTVERSION=	${HALVERSION}.${SNAPVERSION}
PORTREVISION?=	0
CATEGORIES?=	sysutils
MASTER_SITES=	http://www.marcuscom.com/downloads/

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Hardware Abstraction Layer for simplifying device access

.if !defined(HAL_SLAVE)
LIB_DEPENDS=	polkit.0:${PORTSDIR}/sysutils/policykit \
		volume_id.0:${PORTSDIR}/devel/libvolume_id
RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:${PORTSDIR}/misc/pciids
USE_CDRTOOLS=	yes
.endif

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget intlhack ltverhack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-hwdata=${LOCALBASE}/share/pciids \
		--with-backend=freebsd \
		--disable-docbook-docs \
		--with-socket-dir=/var/run/hald \
		--with-pid-file=/var/run/hald/hald.pid
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"

HALVERSION=	0.5.8
SNAPVERSION=	20070403

.if !defined(HAL_SLAVE)
USE_RC_SUBR=	hald
USE_GNOME_SUBR=	yes
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${HALVERSION}
PLIST_SUB=	VERSION=${HALVERSION}

PRIV_FILES=	hal-power-hibernate \
		hal-power-poweroff \
		hal-power-reboot \
		hal-power-suspend \
		hal-storage-fixed-mount-change-uid \
		hal-storage-fixed-mount \
		hal-storage-removable-mount-change-uid \
		hal-storage-removable-mount
PRIV_FILES:=	${PRIV_FILES:S|$|.privilege|}

RC_FILES=	hal.conf:${PREFIX}/etc/dbus-1/system.d \
		${PRIV_FILES:S|$|:${PREFIX}/etc/PolicyKit/privilege.d|}
PLIST_FILES=	${PRIV_FILES:S|^|%%DATADIR%%/dist/|}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	RC_FILES="${RC_FILES}"

OPTIONS=	FIXED_MOUNTPOINTS "use fixed mountpoints" off
.else # Slave port stuff
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

USE_GNOME+=	pygnome2
DESKTOP_ENTRIES="Device Manager" \
		"Examine your devices" \
		"${DATADIR}/device-manager/hal-bus-pci.png" \
		"hal-device-manager" \
		"Application;System;" \
		true
BUILD_WRKSRC=	${WRKSRC}/tools/device-manager
INSTALL_WRKSRC=	${BUILD_WRKSRC}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 505000
IGNORE=	not supported on FreeBSD prior to 5.5-RELEASE
.endif

.if !defined(HAL_SLAVE)
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
.endif

post-patch:
.if !defined(HAL_SLAVE)
	@${REINPLACE_CMD} -e 's|device-manager||' \
		${WRKSRC}/tools/Makefile.in
.endif
	@${REINPLACE_CMD} -e '/^scriptdir = /s|libdir|libexecdir|' \
		${WRKSRC}/tools/Makefile.in \
		${WRKSRC}/tools/freebsd/Makefile.in
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/hal/scripts|(libexecdir)/hal/scripts|' \
		${WRKSRC}/hald/Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|txt||' \
		${WRKSRC}/policy/Makefile.in
	@${REINPLACE_CMD} -e 's|user="0"|group="operator"|g' \
		${WRKSRC}/hal.conf.in
	@${TOUCH} ${WRKSRC}/doc/spec/hal-spec.html

post-install:
.if !defined(HAL_SLAVE)
	${MKDIR} ${DATADIR}/dist
	${INSTALL_DATA} ${WRKSRC}/hal.conf ${WRKSRC}/policy/txt/*.privilege \
		${DATADIR}/dist
	@${SETENV} PKG_PREFIX=${PREFIX} PACKAGE_BUILDING=${PACKAGE_BUILDING} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(PACKAGE_BUILDING) && defined(NEEDS_MEDIA)
	${MKDIR} /media
.endif
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/hald/freebsd/README \
		${DOCSDIR}/README.freebsd
.endif
.endif

.include <bsd.port.post.mk>
