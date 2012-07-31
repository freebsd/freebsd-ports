# New ports collection makefile for:	hplip
# Date created:		1 April 2006
# Whom:			amistry@am-productions.biz
#
# $FreeBSD$
#

PORTNAME=	hplip
PORTVERSION=	3.12.2
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Drivers and utilities for HP Printers and All-in-One devices

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		cupsdriver.1:${PORTSDIR}/print/cups-base \
		cups.2:${PORTSDIR}/print/cups-client \
		cupsimage.2:${PORTSDIR}/print/cups-image \
		dbus-1.3:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	espgs:${PORTSDIR}/print/cups-pstoraster \
		foomatic-rip:${PORTSDIR}/print/foomatic-filters \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus \
		xdg-open:${PORTSDIR}/devel/xdg-utils

CONFLICTS_INSTALL=	hpijs-[0-9]*

USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	2.5+
USE_GNOME=	pkgconfig pygobject

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-foomatic-ppd-install \
		--enable-foomatic-rip-hplip-install \
		--enable-hpijs-install \
		--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
		--with-icondir=${DESKTOPDIR} \
		--with-systraydir=${PREFIX}/etc/xdg/autostart \
		--with-hpppddir=${PREFIX}/share/ppd/HP \
		--with-mimedir=${PREFIX}/etc/cups \
		--with-docdir=${DOCSDIR} \
		--with-drvdir=${PREFIX}/libexec/cups/driver
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=.+\.(c|cpp|h|py)$

FILES4FIX=	Makefile.in \
		base/codes.py \
		base/g.py \
		base/pkit.py \
		base/status.py \
		base/utils.py \
		check.py \
		fax/backend/hpfax.py \
		hplip.list.in \
		installer/core_install.py \
		installer/dcheck.py \
		installer/distros.dat \
		io/hpmud/hp-mkuri.c \
		prnt/cups.py \
		prnt/hpcups/HPCupsFilter.cpp \
		prnt/hpcups/Utils.cpp \
		prnt/hpijs/globals.cpp \
		prnt/hpijs/hpcupsfax.cpp \
		prnt/hpijs/hpijs.cpp \
		setup.py \
		ui/devmgr4.py \
		ui/setupform.py \
		ui4/devmgr5.py

OPTIONS_DEFINE=	QT FAX SNMP SCAN XSANE
OPTIONS_DEFAULT=	QT

QT_DESC=	Graphical User Interface (Qt4)
FAX_DESC=	PC Send Fax support
SNMP_DESC=	Network/JetDirect support
SCAN_DESC=	Scanning support
XSANE_DESC=	Install XSane for scanning (requires SCAN)

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800067
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-strnlen
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
USB_INCLUDE=	${LOCALBASE}/include
.else
USB_INCLUDE=	/usr/include
.endif

.if ${PORT_OPTIONS:MQT}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:${PORTSDIR}/devel/py-qt4-dbus
CONFIGURE_ARGS+=	--enable-qt4 \
			--enable-gui-build
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=	--disable-qt4 \
			--disable-gui-build
PLIST_SUB+=	GUI="@comment "
.endif

.if ${PORT_OPTIONS:MFAX}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab2
CONFIGURE_ARGS+=	--enable-fax-build
PLIST_SUB+=	FAX=""
.else
CONFIGURE_ARGS+=	--disable-fax-build
PLIST_SUB+=	FAX="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
USE_OPENSSL=	yes
LIB_DEPENDS+=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--enable-network-build
. if ${ARCH} == i386
# http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/144833
CONFIGURE_ENV+=	LIBS="-lssp_nonshared"
. endif
.else
CONFIGURE_ARGS+=	--disable-network-build
.endif

.if ${PORT_OPTIONS:MSCAN}
. if ${PORT_OPTIONS:MXSANE}
RUN_DEPENDS+=	xsane:${PORTSDIR}/graphics/xsane
. endif
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging
CONFIGURE_ARGS+=	--enable-scan-build
PLIST_SUB+=	SCAN=""
.else
CONFIGURE_ARGS+=	--disable-scan-build
PLIST_SUB+=	SCAN="@comment "
.endif

.if !${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--enable-doc-build=no
.endif

post-patch:
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},g' \
		-e 's|-ldld||g; s|-ldl||g' \
		${WRKSRC}/configure \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e '/[[:space:]]install-dist_rulesDATA/ s,install-dist_rulesDATA,,' \
		-e '/[[:space:]]install-hplip_confDATA/ s,install-hplip_confDATA,,' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,/etc/hp,${PREFIX}&,g' \
		-e 's,/etc/cups,${LOCALBASE}&,g' \
		-e 's,/etc/init.d,${LOCALBASE}/etc/rc.d,g' \
		-e 's,/etc/sane.d,${LOCALBASE}&,g' \
		-e 's,/usr/share,${LOCALBASE}/share,g' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		${FILES4FIX:S,^,${WRKSRC}/,}
	${REINPLACE_CMD} -e 's,%USB_INCLUDE%,${USB_INCLUDE},' \
		${WRKSRC}/installer/core_install.py
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/[[:space:]]install-docDATA/ s|install-docDATA||' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/hplip-systray.desktop ${PREFIX}/etc/xdg/autostart/hplip-systray.desktop
	${MKDIR} ${PREFIX}/etc/hp
	${INSTALL_DATA} ${WRKSRC}/hplip.conf ${PREFIX}/etc/hp/hplip.conf.sample
	if [ ! -f ${PREFIX}/etc/hp/hplip.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/hp/hplip.conf.sample \
			${PREFIX}/etc/hp/hplip.conf; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
