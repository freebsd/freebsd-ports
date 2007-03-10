# New ports collection makefile for:   uim-gtk
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-gtk

COMMENT=	GTK+ modules of uim input method

USE_GNOME=	gtk20
LIB_DEPENDS=	uim.4:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-gtk2

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-gtk_Makefile.in \
		${PATCHDIR}/extra-patch-helper_Makefile.in 

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/gtk && ${GMAKE} LIBS="-luim")
	(cd ${WRKSRC}/helper && ${GMAKE} LIBS="-luim -luim-custom")

do-install:
	(cd ${WRKSRC}/gtk && ${GMAKE} install)
	(cd ${WRKSRC}/helper && ${GMAKE} install-binPROGRAMS)

.include "${MASTERDIR}/Makefile"
