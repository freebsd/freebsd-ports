# New ports collection makefile for:	gajim
# Date created:				Sun Nov 26 16:36:07 MSK 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	gajim
PORTVERSION=	0.12.2
CATEGORIES=	net-im
MASTER_SITES=	http://www.gajim.org/downloads/ \
		http://ports.internal.vlink.ru/distfiles/

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Gajim is a Jabber client based on a plugin system

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	2.4+
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

MAN1=		gajim.1

ACTIVITIES=	default
EMOTICONS=	animated static static-big
ICONSETS=	crystal dcraven gnome goojim gossip gota jabberbulb nuvola \
		simplebulb stellar sun transports
MOODS=		default

.if !defined(WITHOUT_DBUS)
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
CONFIGURE_ARGS+=	--enable-remote
MAN1+=		gajim-remote.1
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=	--disable-remote
PLIST_SUB+=	DBUS="@comment "
.endif

post-patch:
.for i in gajim-remote.py gajim.py history_manager.py
		${REINPLACE_CMD} -e '1,1s/python/${PYTHON_VERSION}/' \
			${WRKSRC}/src/$i
.endfor

pre-build:
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

post-install:
		${MKDIR} ${DATADIR}/data/activities
		(cd ${WRKSRC}/data/activities && \
		${COPYTREE_SHARE} "${ACTIVITIES}" ${DATADIR}/data/activities)

		${MKDIR} ${DATADIR}/data/emoticons
		(cd ${WRKSRC}/data/emoticons && \
		${COPYTREE_SHARE} "${EMOTICONS}" ${DATADIR}/data/emoticons)

		${MKDIR} ${DATADIR}/data/iconsets
		(cd ${WRKSRC}/data/iconsets && \
		${COPYTREE_SHARE} "${ICONSETS}" ${DATADIR}/data/iconsets)

		${MKDIR} ${DATADIR}/data/moods
		(cd ${WRKSRC}/data/moods && \
		${COPYTREE_SHARE} "${MOODS}" ${DATADIR}/data/moods)

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23
.endif

.include <bsd.port.post.mk>
