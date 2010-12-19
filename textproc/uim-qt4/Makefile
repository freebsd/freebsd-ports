# New ports collection makefile for:	uim-qt4
# Date created:		2008-21-08
# Whom:			Yamashiro Jun <yamajun@ofug.net>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-qt4
PORTREVISION=	1

COMMENT=	Qt4 modules of uim input method

LIB_DEPENDS=	uim.7:${PORTSDIR}/textproc/uim

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build qt3support uic
USE_AUTOTOOLS=	libtool
USE_ICONV=	yes

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-qt4 --with-qt4-immodule
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
	DATADIRNAME="share"
UIM_SLAVE=	yes

.if defined(WITHOUT_X11)
IGNORE=		cannot be built without X11. Please, unset WITHOUT_X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${SETENV} ${MAKE_ENV} ${GMAKE} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/replace && ${SETENV} ${MAKE_ENV} ${GMAKE})
	(cd ${WRKSRC}/qt4 && ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	(cd ${WRKSRC}/qt4 && ${SETENV} ${MAKE_ENV} ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
