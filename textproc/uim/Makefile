# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uim
PORTVERSION=	1.8.8
PORTREVISION?=	2
CATEGORIES?=	textproc
MASTER_SITES=	https://github.com/uim/uim/releases/download/${PORTVERSION}/
.if !defined(UIM_SLAVE) && defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
.endif

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Input method library

LICENSE=	BSD3CLAUSE GPLv2+ GPLv3+ LGPL21+ PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		gettext gmake gnome iconv libedit libtool pathfix pkgconfig perl5 sqlite tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME+=	glib20 intltool
USE_PERL5=	build
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=	X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USES+=		xorg
USE_XORG+=	x11 xext
LIB_DEPENDS+=	libXft.so:x11-fonts/libXft
CONFIGURE_ARGS+=	--with-x --with-xft
.endif

.if !defined(UIM_SLAVE)
.if ${PORT_OPTIONS:MX11}
USE_GNOME+=	cairo gdkpixbuf2 gtk20
LIB_DEPENDS+=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
CONFIGURE_ARGS+=	--with-gtk2
.endif
CONFIGURE_ARGS+=	--enable-emacs --with-sj3 --with-canna --with-prime
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

.if !defined(UIM_SLAVE)
DOCSDIR_JA=	${PREFIX}/share/doc/ja/uim
DOCSDIR_SIGSCHEME=	${PREFIX}/share/doc/uim/sigscheme
PLIST_SUB+=	DOCSDIR_JA="${DOCSDIR_JA:S,^${PREFIX}/,,}" \
		DOCSDIR_SIGSCHEME="${DOCSDIR_SIGSCHEME:S,^${PREFIX}/,,}"
.endif

.if empty(PORT_OPTIONS:MX11)
PLIST_SUB+=	X11="@comment "
.else
PLIST_SUB+=	X11=""
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-storage=fatty
.endif

.for _x in x xft gtk2 qt anthy canna m17nlib prime scim dict
.if ${CONFIGURE_ARGS:M--with-${_x}} == ""
CONFIGURE_ARGS+=--without-${_x}
.endif
.endfor
.for _x in gnome-applet kde-applet emacs pref
.if ${CONFIGURE_ARGS:M--enable-${_x}} == ""
CONFIGURE_ARGS+=--disable-${_x}
.endif
.endfor

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/scm/skk-custom.scm

do-build:
.if !defined(UIM_SLAVE)
.for d in replace sigscheme uim scm xim po fep emacs pixmaps tables
	cd ${WRKSRC}/${d} && ${MAKE_CMD}
.endfor
.if ${PORT_OPTIONS:MX11}
	cd ${WRKSRC}/gtk2/candwin && ${MAKE_CMD}
.endif
.endif

do-install:
.if !defined(UIM_SLAVE)
	cd ${WRKSRC} && ${MAKE_CMD} DESTDIR=${STAGEDIR} install-data-am
.for d in sigscheme uim scm xim po fep emacs pixmaps tables
	cd ${WRKSRC}/${d} && ${MAKE_CMD} DESTDIR=${STAGEDIR} install
.endfor
.if ${PORT_OPTIONS:MX11}
	cd ${WRKSRC}/gtk2/candwin && ${MAKE_CMD} DESTDIR=${STAGEDIR} install
.endif
.endif

.if !defined(UIM_SLAVE)
post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/helperdata
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${STAGEDIR}${DOCSDIR}/KEY
	${INSTALL_DATA} ${WRKSRC}/fep/README ${STAGEDIR}${DOCSDIR}/README.fep
	${INSTALL_DATA} ${WRKSRC}/fep/README ${STAGEDIR}${DOCSDIR}/README.key
	${INSTALL_DATA} ${WRKSRC}/fep/README.ja ${STAGEDIR}${DOCSDIR_JA}/README.fep
	${INSTALL_DATA} ${WRKSRC}/xim/README ${STAGEDIR}${DOCSDIR}/README.xim
.endif

.include <bsd.port.post.mk>
