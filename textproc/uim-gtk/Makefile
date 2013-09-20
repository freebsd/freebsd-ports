# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-gtk

COMMENT=	GTK+ modules of uim input method

USE_GNOME=	gtk20
LIB_DEPENDS=	uim:${PORTSDIR}/textproc/uim

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

NO_STAGE=	yes
do-build:
	(cd ${WRKSRC}/uim && ${GMAKE} libuim-x-util.la libuim-counted-init.la)
	(cd ${WRKSRC}/gtk2/immodule && ${GMAKE})
	(cd ${WRKSRC}/gtk2/pad && ${GMAKE})
	(cd ${WRKSRC}/gtk2/pref && ${GMAKE})
	(cd ${WRKSRC}/gtk2/switcher && ${GMAKE})
	(cd ${WRKSRC}/gtk2/toolbar && ${GMAKE})

do-install:
	(cd ${WRKSRC}/gtk2/immodule && ${GMAKE} install)
	(cd ${WRKSRC}/gtk2/pad && ${GMAKE} install)
	(cd ${WRKSRC}/gtk2/pref && ${GMAKE} install)
	(cd ${WRKSRC}/gtk2/switcher && ${GMAKE} install)
	(cd ${WRKSRC}/gtk2/toolbar && ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
