# New ports collection makefile for:    gnuplot
# Date created:         19 April 1998
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	gnuplot
PORTVERSION=	4.0.0
PORTREVISION=	2
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A command-driven interactive function plotting program

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-tutorial --without-linux-vga --with-lasergnu

OPTIONS=	GD	"Enable GD support"	on \
		PDF	"Enable PDF support"	on \
		PNG	"Enable PNG support"	on

MAN1=		gnuplot.1 lasergnu.1
INFO=		gnuplot

.if exists(${PREFIX}/bin/emacs) || exists(${PREFIX}/bin/xemacs)
EMACS_PORT_NAME=	emacs21
EMACS_NO_BUILD_DEPENDS=	yes
EMACS_NO_RUN_DEPENDS=	yes
CONFIGURE_ARGS+=	--with-lisp-files
.else
PLIST_SUB+=		EMACS_SITE_LISPDIR="@comment "
CONFIGURE_ARGS+=	--without-lisp-files
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500018
CONFIGURE_ARGS+=	--with-readline=gnu
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=		yes
PLIST_SUB+=		X11:=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11:="@comment "
.endif

.if defined(WITHOUT_GD)
CONFIGURE_ARGS+=	--without-gd
.else
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=	--with-gd=${LOCALBASE}
.endif

.if defined(WITHOUT_PDF)
CONFIGURE_ARGS+=	--without-pdf
.else
LIB_DEPENDS+=		pdf.7:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE}
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--without-png
.else
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-png=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|)/@PACKAGE@/@PKG_MAJOR@|)|g' ${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/lasergnu ${PREFIX}/bin
.if exists(${PREFIX}/bin/emacs) || exists(${PREFIX}/bin/xemacs)
	${INSTALL_DATA} ${WRKSRC}/lisp/gnuplot*.el ${EMACS_SITE_LISPDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
