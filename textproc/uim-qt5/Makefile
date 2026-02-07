PKGNAMESUFFIX=	-qt5

COMMENT=	Qt5 modules of uim input method

LIB_DEPENDS=	libuim.so:textproc/uim

USES=		cmake:indirect compiler:c++11-lang gl iconv kde:5 libtool qt:5
USE_GL=		gl
USE_KDE=	plasma-framework \
		ecm:build
USE_QT=		buildtools:build core declarative gui network qmake:build widgets x11extras

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-qt5 --with-qt5-immodule
CONFIGURE_ENV=	DATADIRNAME="share"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
UIM_SLAVE=	yes

.if defined(WITHOUT_X11)
IGNORE=		cannot be built without X11. Please, unset WITHOUT_X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/replace && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})
	(cd ${WRKSRC}/qt5 && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/qt5 && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} DESTDIR=${STAGEDIR} install-strip)

.include "${MASTERDIR}/Makefile"
