# Created by: Samy Al Bahra <samy@kerneled.com>
# $FreeBSD$

PORTNAME=	nvclock
DISTVERSION=	0.8b4
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.8%20%28beta4%29
DISTNAME=	nvclock${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphic card status and overclocking tool

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nvclock bin/smartdimmer man/man1/nvclock.1.gz
PORTDOCS=	ABOUT AUTHORS ChangeLog FAQ README

OPTIONS_DEFINE=	NVCONTROL X11 DOCS
OPTIONS_DEFAULT=	NVCONTROL X11

NVCONTROL_DESC=	NV-CONTROL support (for OpenGL settings)
X11_DESC=	Build GUI program (requires GTK+ 2.x)

NVCONTROL_USE=		XORG=xext
NVCONTROL_USES=		pkgconfig
NVCONTROL_CONFIGURE_OFF=	--disable-nvcontrol

X11_USE=		GNOME=gtk20
X11_PLIST_FILES=	bin/nvclock_gtk share/applications/nvclock.desktop \
			share/icons/hicolor/48x48/apps/nvclock.png
X11_CONFIGURE_OFF=	--disable-gtk

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
INSTALLS_ICONS=	yes
.endif

post-patch:
# Uphold our C[XX]FLAGS except for backend part, it must be compiled with -O0
	@${REINPLACE_CMD} -E 's|^(C(XX)?FLAGS)=|\1+=|' \
		${WRKSRC}/src/gtk/Makefile.in \
		${WRKSRC}/src/qt/Makefile.in \
		${WRKSRC}/src/nvcontrol/Makefile.in
# Prevent recursive prepending of DESTDIR
	@${REINPLACE_CMD} -E '/exec_prefix|bindir/s|\$$\(DESTDIR\)||' \
		${WRKSRC}/src/gtk/Makefile.in \
		${WRKSRC}/src/qt/Makefile.in
	@${REINPLACE_CMD} 's/-lnvcontrol/& @X11_LIBS@/' \
		${WRKSRC}/src/gtk/Makefile.in

.include <bsd.port.mk>
