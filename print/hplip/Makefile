# Created by: amistry@am-productions.biz
# $FreeBSD$

PORTNAME=	hplip
PORTVERSION=	3.16.2
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Drivers and utilities for HP Printers and All-in-One devices

LIB_DEPENDS=	libcupsimage.so:print/cups \
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters \
		${PYTHON_SITELIBDIR}/dbus/_dbus.py:devel/py-dbus

CONFLICTS_INSTALL=	hpijs-[0-9]*

INSTALL_TARGET=	install-strip
USES=		jpeg libtool pkgconfig python
USE_GNOME=	pygobject
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
		--with-icondir=${DESKTOPDIR} \
		--with-systraydir=${PREFIX}/etc/xdg/autostart \
		--with-mimedir=${PREFIX}/share/cups/mime \
		--with-docdir=${DOCSDIR} \
		--with-htmldir=${DOCSDIR} \
		--with-drvdir=${PREFIX}/share/cups/drv
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

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
		prnt/hpijs/globals.cpp \
		prnt/hpijs/hpcupsfax.cpp \
		prnt/hpijs/hpijs.cpp \
		ui/devmgr4.py \
		ui4/devmgr5.py

PYTHON_SITELIBDIR_REL=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}

OPTIONS_DEFINE=	DOCS FAX SNMP SCAN X11 XSANE
OPTIONS_DEFAULT=SNMP SCAN X11
OPTIONS_SUB=	yes # FAX SCAN X11

FAX_DESC=	PC Send Fax support
FAX_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/reportlab/__init__.py:print/py-reportlab2
FAX_CONFIGURE_ENABLE=	fax-build

SNMP_DESC=	Network/JetDirect support
SNMP_USE=	OPENSSL=yes
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_ENABLE=	network-build

SCAN_DESC=	Scanning support
SCAN_LIB_DEPENDS=	libsane.so:graphics/sane-backends
SCAN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow
SCAN_CONFIGURE_ENABLE=	scan-build

X11_DESC=	Graphical User Interface (Qt 4)
X11_RUN_DEPENDS=${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:devel/py-qt4-dbussupport
X11_CONFIGURE_ENABLE=	qt4 gui-build

XSANE_DESC=	Install XSane for scanning (requires SCAN)
XSANE_IMPLIES=	SCAN
XSANE_RUN_DEPENDS=	xsane:graphics/xsane

DOCS_CONFIGURE_ENABLE=	doc-build

post-patch:
	${REINPLACE_CMD} -e 's|-ldld||g; s|-ldl||g' \
		-e 's,-lusb-1.0,-lusb,g' \
		-e 's,libusb-1.0/libusb.h,libusb.h,g' \
		${WRKSRC}/configure \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e '/[[:space:]]install-dist_rulesDATA/ s,install-dist_rulesDATA,,' \
		-e '/[[:space:]]install-dist_rulessystemDATA/ s,install-dist_rulessystemDATA,,' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,/etc/hp,${PREFIX}&,g' \
		-e 's,/etc/cups,${LOCALBASE}&,g' \
		-e 's,/etc/init.d,${LOCALBASE}/etc/rc.d,g' \
		-e 's,/etc/sane.d,${LOCALBASE}&,g' \
		-e 's,/usr/share,${LOCALBASE}/share,g' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		${FILES4FIX:S,^,${WRKSRC}/,}
	@${REINPLACE_CMD} -e 's/umask(0)/umask(0o022)/' \
		-e 's/umask(0o111)/umask(0o133)/' \
		${WRKSRC}/base/os_utils.py \
		${WRKSRC}/base/validation.py \
		${WRKSRC}/fax/backend/hpfax.py \
		${WRKSRC}/hpdio.py \
		${WRKSRC}/installer/pluginhandler.py
	${REINPLACE_CMD} -e 's,%USB_INCLUDE%,/usr/include,' \
		${WRKSRC}/installer/core_install.py
	${FIND} ${WRKSRC} -name '*.py' | ${XARGS} ${SED} -i '' \
		-e 's,^#!/usr/bin/python,#!${PYTHON_CMD},' \
		-e 's,^#!/usr/bin/env python,#!${PYTHON_CMD},' \
		-e 's,^#!/bin/env python,#!${PYTHON_CMD},'

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/hp/hplip.conf \
		${STAGEDIR}${PREFIX}/etc/hp/hplip.conf.sample

.include <bsd.port.mk>
