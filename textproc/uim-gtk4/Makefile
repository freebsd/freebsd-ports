PKGNAMESUFFIX=	-gtk4

COMMENT=	GTK 4.x modules of uim input method

USE_GNOME=	cairo gdkpixbuf gtk40
LIB_DEPENDS=	libuim.so:textproc/uim \
		libharfbuzz.so:print/harfbuzz

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-gtk4 --enable-default-toolkit=gtk4

UIM_SLAVE=	yes

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${MAKE_CMD} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/gtk4/immodule && ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/gtk4/immodule && ${MAKE_CMD} DESTDIR=${STAGEDIR} install-strip)

.include "${MASTERDIR}/Makefile"
