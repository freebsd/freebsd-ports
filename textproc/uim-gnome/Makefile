# New ports collection makefile for:   uim-gnome
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-gnome

COMMENT=	GNOME applets of uim input method

USE_GNOME=	gtk20 gnomepanel
LIB_DEPENDS=	uim.2:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-gtk2 --with-gnome2 --enable-applet

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-helper_Makefile.in 

do-build:
	(cd ${WRKSRC}/helper && ${GMAKE} LIBS="-luim -luim-custom")

do-install:
	(cd ${WRKSRC}/helper && \
	${GMAKE} am__EXEEXT_3="" install-serverDATA install-libexecPROGRAMS)

.include "${MASTERDIR}/Makefile"
