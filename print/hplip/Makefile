# Created by: amistry@am-productions.biz
# $FreeBSD$

PORTNAME=	hplip
PORTVERSION=	3.14.4
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Drivers and utilities for HP Printers and All-in-One devices

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libcupsmime.so:${PORTSDIR}/print/cups-base \
		libcups.so:${PORTSDIR}/print/cups-client \
		libcupsimage.so:${PORTSDIR}/print/cups-image \
		libdbus-1.so:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	espgs:${PORTSDIR}/print/cups-pstoraster \
		foomatic-rip:${PORTSDIR}/print/foomatic-filters \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:${PORTSDIR}/devel/py-dbus \
		xdg-open:${PORTSDIR}/devel/xdg-utils

CONFLICTS_INSTALL=	hpijs-[0-9]*

INSTALL_TARGET=	install-strip
USES=		dos2unix libtool pkgconfig shebangfix
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_GNOME=	pygobject
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-foomatic-ppd-install \
		--enable-hpijs-install \
		--enable-cups-ppd-install \
		--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
		--with-icondir=${DESKTOPDIR} \
		--with-systraydir=${PREFIX}/etc/xdg/autostart \
		--with-hpppddir=${PREFIX}/share/ppd/HP \
		--with-mimedir=${PREFIX}/etc/cups \
		--with-docdir=${DOCSDIR} \
		--with-htmldir=${DOCSDIR} \
		--with-drvdir=${PREFIX}/libexec/cups/driver \
		--enable-libusb01_build
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
DOS2UNIX_REGEX=.+\.(c|cpp|h|py)$
SHEBANG_FILES=	prnt/hpijs/foomatic-rip-hplip
FILES4FIX=	Makefile.in \
		base/codes.py \
		base/g.py \
		base/password.py \
		base/pkit.py \
		base/queues.py \
		base/services.py \
		base/utils.py \
		check.py \
		fax/backend/hpfax.py \
		fax/coverpages.py \
		fax/filters/pstotiff \
		hplip.list.in \
		installer/core_install.py \
		installer/dcheck.py \
		installer/pluginhandler.py \
		logcapture.py \
		prnt/cups.py \
		prnt/filters/hpps \
		prnt/hpcups/HPCupsFilter.cpp \
		prnt/hpijs/foomatic-rip-hplip \
		prnt/hpijs/globals.cpp \
		prnt/hpijs/hpcupsfax.cpp \
		prnt/hpijs/hpijs.cpp \
		ui/devmgr4.py \
		ui4/devmgr5.py

PYTHON_SITELIBDIR_REL=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

OPTIONS_DEFINE=	QT FAX SNMP SCAN XSANE DOCS
OPTIONS_DEFAULT=	QT
OPTIONS_SUB=		yes # QT FAX SCAN

QT_DESC=	Graphical User Interface (Qt 4)
QT_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:${PORTSDIR}/devel/py-qt4-dbussupport
QT_CONFIGURE_ENABLE=	qt4 gui-build

FAX_DESC=	PC Send Fax support
FAX_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab2
FAX_CONFIGURE_ENABLE=	fax-build

SNMP_DESC=	Network/JetDirect support
SNMP_USE=	OPENSSL=yes
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
SNMP_CONFIGURE_ENABLE=	network-build

SCAN_DESC=	Scanning support
SCAN_LIB_DEPENDS=	libsane.so:${PORTSDIR}/graphics/sane-backends
SCAN_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging
SCAN_CONFIGURE_ENABLE=	scan-build

XSANE_DESC=	Install XSane for scanning (requires SCAN)

DOCS_CONFIGURE_ENABLE=	doc-build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSCAN}
. if ${PORT_OPTIONS:MXSANE}
RUN_DEPENDS+=	xsane:${PORTSDIR}/graphics/xsane
. endif
.endif

post-patch:
	${REINPLACE_CMD} -e 's|-ldld||g; s|-ldl||g' \
		${WRKSRC}/configure \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e '/[[:space:]]install-dist_rulesDATA/ s,install-dist_rulesDATA,,' \
		-e '/[[:space:]]install-hplip_confDATA/ s,install-hplip_confDATA,,' \
		-e '/[[:space:]]install-dist_hplip_LogDATA/ s,install-dist_hplip_LogDATA,,' \
		-e '/[[:space:]]install-dist_cronDATA/ s,install-dist_cronDATA,,' \
		-e '/[[:space:]]install-dist_halpreDATA/ s,install-dist_halpreDATA,,' \
		-e '/[[:space:]]install-dist_hplip_stateDATA/ s,install-dist_hplip_stateDATA,,' \
		-e '/[[:space:]]install-dist_hplip_tmpDATA/ s,install-dist_hplip_tmpDATA,,' \
		-e '/[[:space:]]install-dist_rulessystemDATA/ s,install-dist_rulessystemDATA,,' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,/etc/hp,${PREFIX}&,g' \
		-e 's,/etc/cups,${LOCALBASE}&,g' \
		-e 's,/etc/foomatic,${LOCALBASE}&,g' \
		-e 's,/etc/init.d,${LOCALBASE}/etc/rc.d,g' \
		-e 's,/etc/sane.d,${LOCALBASE}&,g' \
		-e 's,/usr/share,${LOCALBASE}/share,g' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		${FILES4FIX:S,^,${WRKSRC}/,}
	${REINPLACE_CMD} -e 's,%USB_INCLUDE%,/usr/include,' \
		${WRKSRC}/installer/core_install.py
	${FIND} ${WRKSRC} -name '*.py' | ${XARGS} ${SED} -i '' \
		-e 's,^#!/usr/bin/python,#!${PYTHON_CMD},' \
		-e 's,^#!/usr/bin/env python,#!${PYTHON_CMD},' \
		-e 's,^#!/bin/env python,#!${PYTHON_CMD},'
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/[[:space:]]install-docDATA/ s|install-docDATA||' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MQT}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${WRKSRC}/hplip-systray.desktop ${STAGEDIR}${PREFIX}/etc/xdg/autostart/hplip-systray.desktop
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hp
	${INSTALL_DATA} ${WRKSRC}/hplip.conf ${STAGEDIR}${PREFIX}/etc/hp/hplip.conf.sample
	${LN} -sf ${LOCALBASE}/bin/foomatic-rip ${STAGEDIR}${PREFIX}/libexec/cups/filter/foomatic-rip-hplip

.include <bsd.port.mk>
