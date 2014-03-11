# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-gnome

COMMENT=	GNOME applets of uim input method

USE_GNOME=	gtk20 gnomepanel libgnomeui
LIB_DEPENDS=	uim:${PORTSDIR}/textproc/uim
RUN_DEPENDS=	uim-pref-gtk:${PORTSDIR}/textproc/uim-gtk

DEPRECATED=	gnome-panel 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	`pkg-config --cflags libgnomeui-2.0`
CONFIGURE_ARGS=	--with-gtk2 --enable-gnome-applet

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-gtk2_toolbar_Makefile.in

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

NO_STAGE=	yes
do-build:
	(cd ${WRKSRC}/gtk2/toolbar && ${GMAKE})

do-install:
	(cd ${WRKSRC}/gtk2/toolbar && \
	${GMAKE} install-serverDATA install-libexecPROGRAMS)

.include "${MASTERDIR}/Makefile"
