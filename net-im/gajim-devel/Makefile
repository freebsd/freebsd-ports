# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	gajim
PORTVERSION=	20101030
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.bamus.cz/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-2010-10-30

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gajim is a Jabber client based on a plugin system

DEPRECATED=	This port is outdated for two years, no distfile available. Please use net-im/gajim instead
EXPIRATION_DATE=2013-04-18

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_PORTVERSION}:${PORTSDIR}/databases/py-sqlite3

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	2.5+
USE_XORG=	x11 xext xscrnsaver

CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-0.14.0.1-aa675b5a84e1

MAN1=		gajim.1 gajim-history-manager.1 gajim-remote.1

pre-build:
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

.include <bsd.port.mk>
