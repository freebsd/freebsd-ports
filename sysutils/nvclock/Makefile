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

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nvclock bin/smartdimmer
MAN1=		nvclock.1
PORTDOCS=	ABOUT AUTHORS ChangeLog FAQ README

OPTIONS_DEFINE=	NVCONTROL GTK2 QT3 DOCS
OPTIONS_DEFAULT=	NVCONTROL GTK2

NVCONTROL_DESC=	NV-CONTROL support (for OpenGL settings)
GTK2_DESC=	Build GTK+ 2 GUI program
QT3_DESC=	Build Qt 3.x (legacy) GUI program

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVCONTROL}
USE_XORG=	xext
USE_GNOME=	pkgconfig
.else
CONFIGURE_ARGS+=	--disable-nvcontrol
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
PLIST_FILES+=	bin/nvclock_gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if ${PORT_OPTIONS:MQT3}
USE_QT_VER=	3
CONFIGURE_ARGS+=	--enable-qt --with-qtdir=${LOCALBASE}
PLIST_FILES+=	bin/nvclock_qt
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
