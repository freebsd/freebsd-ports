# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	system-config-printer
PORTVERSION=	1.4.7
PORTREVISION=	3
CATEGORIES=	print gnome
MASTER_SITES=	http://cyberelk.net/tim/data/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CUPS configuration Gtk+2.0 GUI

BUILD_DEPENDS=	xmlto:textproc/xmlto \
		docbook-xml>0:textproc/docbook-xml
LIB_DEPENDS=	libcups.so:print/cups
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycups>=0:print/py-pycups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>=0:ftp/py-pycurl@${PY_FLAVOR} \
		${LOCALBASE}/libexec/cups-pk-helper-mechanism:print/cups-pk-helper

# 1.5 series is python3 ignore them for now.
PORTSCOUT=	limitw:1,even

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig python:2 \
		shebangfix tar:xz
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	intlhack pygobject3

CONFIGURE_ARGS=	--without-udev-rules \
		--without-systemdsystemunitdir

PLIST_SUB=	PYTHON_VER=${PYTHON_VERSION:S/python//}

SHEBANG_FILES=	*.py troubleshoot/*.py xml/validate.py

PYDISTUTILS_PKGNAME=	cupshelpers
PYDISTUTILS_PKGVERSION=	1.0

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/applet.py ${WRKSRC}/check-device-ids.py \
		${WRKSRC}/cupshelpers/cupshelpers.py \
		${WRKSRC}/cupshelpers/xmldriverprefs.py \
		${WRKSRC}/dbus/org.fedoraproject.Config.Printing.service \
		${WRKSRC}/newprinter.py ${WRKSRC}/probe_printer.py
	@${REINPLACE_CMD} -e 's|setup.py install.*|setup.py install -c -O1 --prefix=${PREFIX} --root=${STAGEDIR}|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
