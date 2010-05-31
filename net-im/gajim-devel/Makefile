# New ports collection makefile for:	gajim-devel
# Date created:				Sun Nov 26 16:36:07 MSK 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	gajim
PORTVERSION=	20100116
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://wizard.volgograd.ru/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-2010-01-16

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Gajim is a Jabber client based on a plugin system

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

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" PYTHON=${PYTHON_CMD}

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-0.13.10.1-dev

MAN1=		gajim.1 gajim-remote.1

pre-build:
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

.include <bsd.port.mk>
