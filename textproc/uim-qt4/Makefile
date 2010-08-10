# New ports collection makefile for:	uim-qt4
# Date created:		2008-21-08
# Whom:			Yamashiro Jun <yamajun@ofug.net>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-qt4

COMMENT=	Qt4 IM modules of uim input method

LIB_DEPENDS=	uim.6:${PORTSDIR}/textproc/uim

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build qt3support
USE_AUTOTOOLS=	libtool:22
USE_ICONV=	yes

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-qt4-immodule
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib -I${LOCALBASE}/include "
UIM_SLAVE=	yes

PLIST_FILES=	${QT_PLUGINDIR_REL}/inputmethods/libuiminputcontextplugin.so
PLIST_DIRS=	${QT_PLUGINDIR_REL}/inputmethods \
		${QT_PLUGINDIR_REL}

.if defined(WITHOUT_X11)
IGNORE=		cannot be built without X11. Please, unset WITHOUT_X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${SETENV} ${MAKE_ENV} ${GMAKE} libuim-x-util.la)
	(cd ${WRKSRC}/replace && ${SETENV} ${MAKE_ENV} ${GMAKE})
	(cd ${WRKSRC}/qt4/immodule && ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	(cd ${WRKSRC}/qt4/immodule && ${SETENV} ${MAKE_ENV} ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
