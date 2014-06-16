# Created by: Yamashiro Jun <yamajun@ofug.net>
# $FreeBSD$

PKGNAMESUFFIX=	-qt4

COMMENT=	Qt4 modules of uim input method

LIB_DEPENDS=	libuim.so:${PORTSDIR}/textproc/uim

USE_QT4=	qmake_build moc_build qt3support uic
USE_AUTOTOOLS=	libtool
USES=		iconv

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-qt4 --with-qt4-immodule
CONFIGURE_ENV=	DATADIRNAME="share"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
UIM_SLAVE=	yes

.if defined(WITHOUT_X11)
IGNORE=		cannot be built without X11. Please, unset WITHOUT_X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${SETENV} ${MAKE_ENV} ${GMAKE} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/replace && ${SETENV} ${MAKE_ENV} ${GMAKE})
	(cd ${WRKSRC}/qt4 && ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	(cd ${WRKSRC}/qt4 && ${SETENV} ${MAKE_ENV} ${GMAKE} DESTDIR=${STAGEDIR} install)

.include "${MASTERDIR}/Makefile"
