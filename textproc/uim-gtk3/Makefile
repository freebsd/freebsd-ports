# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>

PKGNAMESUFFIX=	-gtk3

COMMENT=	GTK+ 3.x modules of uim input method

USE_GNOME=	cairo gdkpixbuf2 gtk30
LIB_DEPENDS=	libuim.so:textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-gtk3 --enable-pref --enable-default-toolkit=gtk3

UIM_SLAVE=	yes

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${MAKE_CMD} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/gtk3/immodule && ${MAKE_CMD})
	(cd ${WRKSRC}/gtk3/pad && ${MAKE_CMD})
	(cd ${WRKSRC}/gtk3/pref && ${MAKE_CMD})
	(cd ${WRKSRC}/gtk3/switcher && ${MAKE_CMD})
	(cd ${WRKSRC}/gtk3/toolbar && ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/gtk3/immodule && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)
	(cd ${WRKSRC}/gtk3/pad && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)
	(cd ${WRKSRC}/gtk3/pref && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)
	(cd ${WRKSRC}/gtk3/switcher && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)
	(cd ${WRKSRC}/gtk3/toolbar && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)

.include "${MASTERDIR}/Makefile"
