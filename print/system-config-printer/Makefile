# New ports collection makefile for:	system-config-printer
# Date created:		2008-03-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/print/system-config-printer/Makefile,v 1.6 2009/12/29 16:03:58 ahze Exp $
#

PORTNAME=	system-config-printer
PORTVERSION=	1.1.16
PORTREVISION=	1
CATEGORIES=	print gnome
MASTER_SITES=	http://cyberelk.net/tim/data/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CUPS configuration Gtk+2.0 GUI

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups \
		${LOCALBASE}/libdata/pkgconfig/notify-python.pc:${PORTSDIR}/devel/py-notify \
		xmlproc_parse:${PORTSDIR}/textproc/py-xml \
		${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		xmlto:${PORTSDIR}/textproc/xmlto \
		desktop-file-install:${PORTSDIR}/devel/desktop-file-utils
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups \
		${LOCALBASE}/libdata/pkgconfig/notify-python.pc:${PORTSDIR}/devel/py-notify \
		xmlproc_parse:${PORTSDIR}/textproc/py-xml \
		${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/libexec/cups-pk-helper-mechanism:${PORTSDIR}/print/cups-pk-helper

USE_BZIP2=	yes
USE_PYTHON=	2.6+
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	pygtk2
MAN1=	system-config-printer-applet.1 system-config-printer.1
PLIST_SUB=	PYTHON_VER=${PYTHON_VERSION:S/python//}

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g; s|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.mk>
