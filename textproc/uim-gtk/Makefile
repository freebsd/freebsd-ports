# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-gtk

COMMENT=	GTK+ modules of uim input method

USE_GNOME=	gtk20
LIB_DEPENDS=	libuim.so:textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-gtk2 --enable-pref

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-gtk2_immodule_Makefile.in \
		${PATCHDIR}/extra-patch-gtk2_pad_Makefile.in \
		${PATCHDIR}/extra-patch-gtk2_pref_Makefile.in \
		${PATCHDIR}/extra-patch-gtk2_switcher_Makefile.in \
		${PATCHDIR}/extra-patch-gtk2_toolbar_Makefile.in

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${MAKE_CMD} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/gtk2/immodule && ${MAKE_CMD})
	(cd ${WRKSRC}/gtk2/pad && ${MAKE_CMD})
	(cd ${WRKSRC}/gtk2/pref && ${MAKE_CMD})
	(cd ${WRKSRC}/gtk2/switcher && ${MAKE_CMD})
	(cd ${WRKSRC}/gtk2/toolbar && ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/gtk2/immodule && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)
	(cd ${WRKSRC}/gtk2/pad && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)
	(cd ${WRKSRC}/gtk2/pref && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)
	(cd ${WRKSRC}/gtk2/switcher && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)
	(cd ${WRKSRC}/gtk2/toolbar && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)

.include "${MASTERDIR}/Makefile"
