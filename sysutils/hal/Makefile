# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/hal/Makefile,v 1.81 2010/04/13 02:49:07 mezz Exp $

PORTNAME=	hal
DISTVERSION=	0.5.14
PORTREVISION=	34
CATEGORIES=	sysutils
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Hardware Abstraction Layer for simplifying device access

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
# keep shlib version, to prevent confusion with polkit-* from sysutils/polkit
LIB_DEPENDS=	libpolkit.so.2:sysutils/policykit \
		libvolume_id.so:devel/libvolume_id \
		libck-connector.so:sysutils/consolekit2
RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids

USES=		gettext gmake gnome libtool:keepla pathfix pkgconfig python \
		shebangfix
USE_GNOME=	intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
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
CONFIGURE_ENV=	GTKDOC="false"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
bash_CMD=	${SH}
SHEBANG_FILES=	tools/hal-*

#HALVERSION=	0.5.10
#SNAPVERSION=	20080218

USERS=		haldaemon
GROUPS=		haldaemon

USE_RC_SUBR=	hald
USE_GNOME_SUBR=	yes
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}
PLIST_SUB=	VERSION=${DISTVERSION}

RC_FILES=	hal.conf:${PREFIX}/etc/dbus-1/system.d
PLIST_FILES=	${PRIV_FILES:S|^|%%DATADIR%%/dist/|}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	RC_FILES="${RC_FILES}"

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	FIXED_MOUNTPOINTS DOCS
FIXED_MOUNTPOINTS_DESC=	use fixed mountpoints
FIXED_MOUNTPOINTS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-tools_hal-storage-mount.c

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
RUN_DEPENDS+=	dmidecode:sysutils/dmidecode
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/==/=/g' ${WRKSRC}/tools/hal-luks*
	@${REINPLACE_CMD} -e '/^scriptdir = /s|[(]libexecdir[)]/scripts|(libexecdir)/hal/scripts|' \
		${WRKSRC}/tools/Makefile.in \
		${WRKSRC}/tools/freebsd/Makefile.in
	@${REINPLACE_CMD} -e 's|[(]libexecdir[)]/scripts|(libexecdir)/hal/scripts|' \
		${WRKSRC}/hald/Makefile.in \
		${WRKSRC}/tools/Makefile.in
	@${REINPLACE_CMD} -e 's|user="0"|group="operator"|g' \
		${WRKSRC}/hal.conf.in
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		< ${FILESDIR}/README.fuse > ${WRKDIR}/README.fuse

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/dist
	${INSTALL_DATA} ${WRKSRC}/hal.conf ${STAGEDIR}${DATADIR}/dist
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/hal/fdi/policy/10osvendor
	${INSTALL_DATA} ${FILESDIR}/10-mouse-sysmouse.fdi \
		${STAGEDIR}${PREFIX}/share/hal/fdi/policy/10osvendor
	${INSTALL_SCRIPT} ${FILESDIR}/mount-fuse \
		${STAGEDIR}${PREFIX}/share/hal/mount-fuse
	@${MKDIR} ${STAGEDIR}/var/lib/hal

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/hald/freebsd/README \
		${STAGEDIR}${DOCSDIR}/README.freebsd
	${INSTALL_DATA} ${WRKDIR}/README.fuse \
		${STAGEDIR}${DOCSDIR}/README.fuse

.include <bsd.port.post.mk>
