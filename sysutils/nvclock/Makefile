# New ports collection makefile for:	NVClock
# Date created:				August 4, 2003
# Whom:					Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	nvclock
DISTVERSION=	0.8b4
PORTREVISION=	4
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

OPTIONS=	NVCONTROL	"Enable NV-CONTROL support"	on \
		GTK		"Build GTK+ user interface"	on \
		QT		"Build Qt 3.x user interface"	off

.include <bsd.port.options.mk>

.if defined(WITH_NVCONTROL)
USE_XORG=	xext
USE_GNOME=	pkgconfig
.else
CONFIGURE_ARGS+=	--disable-nvcontrol
.endif

.if defined(WITH_GTK)
USE_GNOME=	gtk20
PLIST_FILES+=	bin/nvclock_gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if defined(WITH_QT)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${GMAKE} -C ${WRKSRC} install-docs
.endif

.include <bsd.port.mk>
