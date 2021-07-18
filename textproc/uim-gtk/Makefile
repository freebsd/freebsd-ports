# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>

PKGNAMESUFFIX=	-gtk

COMMENT=	GTK+ modules of uim input method

USE_GNOME=	cairo gdkpixbuf2 gtk20
LIB_DEPENDS=	libuim.so:textproc/uim \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-gtk2 --enable-pref

UIM_SLAVE=	yes

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${MAKE_CMD} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/gtk2 && ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/gtk2 && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)

.include "${MASTERDIR}/Makefile"
