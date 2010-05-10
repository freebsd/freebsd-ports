# New ports collection makefile for:   uim-gnome
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-gnome
PORTREVISION=	4

COMMENT=	GNOME applets of uim input method

USE_GNOME=	gtk20 gnomepanel libgnomeui
LIB_DEPENDS=	uim.6:${PORTSDIR}/textproc/uim
RUN_DEPENDS=	uim-pref-gtk:${PORTSDIR}/textproc/uim-gtk

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ENV=	CPPFLAGS="`pkg-config --cflags libgnomeui-2.0`" \
		LIBS="`pkg-config --libs libgnomeui-2.0`"
CONFIGURE_ARGS=	--with-gtk2 --enable-gnome-applet

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-helper_Makefile.in 

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

do-build:
	(cd ${WRKSRC}/helper && ${GMAKE})

do-install:
	(cd ${WRKSRC}/helper && \
	${GMAKE} am__EXEEXT_3="" install-serverDATA install-libexecPROGRAMS)

.include "${MASTERDIR}/Makefile"
