# Created by: Samy Al Bahra <samy@kerneled.com>
# $FreeBSD$

PORTNAME=	nvclock
DISTVERSION=	0.8b4
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.8%20%28beta4%29
DISTNAME=	nvclock${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphic card status and overclocking tool

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nvclock bin/smartdimmer
MAN1=		nvclock.1
PORTDOCS=	ABOUT AUTHORS ChangeLog FAQ README

OPTIONS_DEFINE=	NVCONTROL X11 DOCS
OPTIONS_DEFAULT=	NVCONTROL X11

NVCONTROL_DESC=	NV-CONTROL support (for OpenGL settings)
X11_DESC=	Build GUI program (requires GTK+ 2.x)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVCONTROL}
USE_XORG=	xext
USES+=		pkgconfig
.else
CONFIGURE_ARGS+=	--disable-nvcontrol
.endif

.if ${PORT_OPTIONS:MX11}
USE_GNOME=	gtk20
PLIST_FILES+=	bin/nvclock_gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

post-patch:
# Uphold our C[XX]FLAGS except for backend part, it must be compiled with -O0
	@${REINPLACE_CMD} -E 's|^(C(XX)?FLAGS)=|\1+=|' \
		${WRKSRC}/src/gtk/Makefile.in \
		${WRKSRC}/src/qt/Makefile.in \
		${WRKSRC}/src/nvcontrol/Makefile.in

do-install:
	${GMAKE} -C ${WRKSRC}/src install
	${GMAKE} -C ${WRKSRC} install-man
.if ${PORT_OPTIONS:MDOCS}
	${GMAKE} -C ${WRKSRC} install-docs
.endif

.include <bsd.port.mk>
