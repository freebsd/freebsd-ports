# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/print/system-config-printer/Makefile,v 1.6 2009/12/29 16:03:58 ahze Exp $

PORTNAME=	system-config-printer
PORTVERSION=	1.4.2
CATEGORIES=	print gnome
MASTER_SITES=	http://cyberelk.net/tim/data/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CUPS configuration Gtk+2.0 GUI

BUILD_DEPENDS=	xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/share/xml/docbook/4.1.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-sk
LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups \
		${PYTHON_SITELIBDIR}/pycurl.so:${PORTSDIR}/ftp/py-curl \
		${LOCALBASE}/libexec/cups-pk-helper-mechanism:${PORTSDIR}/print/cups-pk-helper

USE_XZ=		yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig shebangfix
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	intlhack pygobject3

CONFIGURE_ARGS=	--without-udev-rules \
		--without-systemdsystemunitdir

MAN1=		system-config-printer-applet.1 \
		system-config-printer.1
PLIST_SUB=	PYTHON_VER=${PYTHON_VERSION:S/python//}

SHEBANG_FILES=	*.py troubleshoot/*.py xml/validate.py

INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGNAME=	cupshelpers
PYDISTUTILS_PKGVERSION=	1.0

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/applet.py ${WRKSRC}/check-device-ids.py \
		${WRKSRC}/cupshelpers/cupshelpers.py \
		${WRKSRC}/cupshelpers/xmldriverprefs.py \
		${WRKSRC}/dbus/org.fedoraproject.Config.Printing.service \
		${WRKSRC}/newprinter.py ${WRKSRC}/probe_printer.py
	@${REINPLACE_CMD} -e 's|setup.py install|setup.py install -c -O1|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
