PKGNAMESUFFIX=	-qt5

COMMENT=	Qt5 modules of uim input method

LICENSE=	BSD3CLAUSE GPLv2+ GPLv3+ LGPL21+ PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libuim.so:textproc/uim

USES=		compiler:c++11-lang gl iconv kde:5 libtool qt:5
USE_GL=		gl
USE_KDE=	plasma-framework
USE_QT=		buildtools_build core declarative gui network qmake_build widgets x11extras

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
	(cd ${WRKSRC}/qt5 && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} DESTDIR=${STAGEDIR} install)

.include "${MASTERDIR}/Makefile"
