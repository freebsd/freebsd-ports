# New ports collection makefile for:	PenguinTV-devel
# Date created:				14 March 2006
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$

PORTNAME=	PenguinTV
PORTVERSION=	2.0.3
CATEGORIES=	net audio multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	penguintv

MAINTAINER=	edwin@mavetju.org
COMMENT=	Graphical RSS feed reader with incorperated playback functions

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite21 \
		${PYTHON_SITELIBDIR}/pycurl.so:${PORTSDIR}/ftp/py-curl \
		${PYXML}
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+= Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	MOZILLA	"Use Mozilla rendered (experimental)" OFF

USE_GNOME=	gnomehier pygnomeextras pygnome2
USE_PYTHON=	yes

GCONF_SCHEMAS=	penguintv.schema

CONFLICTS=	PenguinTV-devel-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_MOZILLA)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/Pyrex/__init__.py:${PORTSDIR}/devel/pyrex \
		mozilla-config:${PORTSDIR}/www/mozilla
PLIST_SUB+=	WITH_MOZILLA=""
.else
EXTRA_PATCHES+=	${FILESDIR}/patchmozilla-setup.py
PLIST_SUB+=	WITH_MOZILLA="@comment "
.endif

pre-fetch:
	@${ECHO_MSG} If you are upgrading from 1.x, please export your subscriptions for save-keeping!
	@${ECHO_MSG} The database scheme should be upgraded automatically.
	@sleep 5

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install

post-install:
	@${MKDIR} ${LOCALBASE}/etc/gconf/schemas
	@${INSTALL_DATA} ${WRKSRC}/share/penguintv.schema \
		${LOCALBASE}/etc/gconf/schemas/

.include <bsd.port.post.mk>
