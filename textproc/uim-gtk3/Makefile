# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-gtk3

COMMENT=	GTK+ 3.x modules of uim input method

USE_GNOME=	gtk30
LIB_DEPENDS=	libuim.so:textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-gtk3 --enable-pref --enable-default-toolkit=gtk3

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-gtk3_candwin_Makefile.in \
		${PATCHDIR}/extra-patch-gtk3_dict_Makefile.in \
		${PATCHDIR}/extra-patch-gtk3_immodule_Makefile.in \
		${PATCHDIR}/extra-patch-gtk3_pad_Makefile.in \
		${PATCHDIR}/extra-patch-gtk3_pref_Makefile.in \
		${PATCHDIR}/extra-patch-gtk3_switcher_Makefile.in \
		${PATCHDIR}/extra-patch-gtk3_toolbar_Makefile.in

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/uim && ${MAKE_CMD} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/gtk3 && ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/gtk3 && ${MAKE_CMD} DESTDIR=${STAGEDIR} install)

.include "${MASTERDIR}/Makefile"
