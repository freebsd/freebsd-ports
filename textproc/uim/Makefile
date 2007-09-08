# New ports collection makefile for:   uim
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uim
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES?=	textproc
MASTER_SITES=	http://uim.freedesktop.org/releases/
.if !defined(UIM_SLAVE) && defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
.endif

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Input method library

INSTALLS_SHLIB=	yes
WANT_GNOME=	yes
USE_GNOME+=	gnometarget glib20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--with-x --with-xft
.endif

.if !defined(UIM_SLAVE)
.if !defined(WITHOUT_X11)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk2
.endif
CONFIGURE_ARGS+=	--enable-emacs
.endif

CONFIGURE_ENV?=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib  -L${LOCALBASE}/lib"

.if !defined(UIM_SLAVE)
.if !defined(WITHOUT_X11)
MAN1=		uim-xim.1
.endif
DOCSDIR_JA=	${PREFIX}/share/doc/ja/uim
PLIST_SUB=	DOCSDIR_JA="${DOCSDIR_JA:S,^${PREFIX}/,,}"
.endif

.if defined(WITHOUT_X11)
PLIST_SUB+=	X11="@comment "
.else
PLIST_SUB+=	X11=""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-uim_editline.c
.endif

USE_PERL5_BUILD=yes

.for _x in x xft gtk2 qt gnome2 anthy canna m17nlib prime scim dict
.if ${CONFIGURE_ARGS:M--with-${_x}} == ""
CONFIGURE_ARGS+=--without-${_x}
.endif
.endfor
.if ${CONFIGURE_ARGS:M--enable-applet} == ""
CONFIGURE_ARGS+=--disable-applet
.endif

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/scm/skk-custom.scm

do-build:
.if !defined(UIM_SLAVE)
.for d in replace uim scm xim po fep emacs pixmaps
	cd ${WRKSRC}/${d} && ${GMAKE}
.endfor
	cd ${WRKSRC}/helper && ${GMAKE}
.endif

do-install:
.if !defined(UIM_SLAVE)
	cd ${WRKSRC} && ${GMAKE} install-data-am
.for d in uim scm xim po fep emacs pixmaps
	cd ${WRKSRC}/${d} && ${GMAKE} install
.endfor
	cd ${WRKSRC}/helper && ${GMAKE} install-libexecPROGRAMS
.endif

.if !defined(UIM_SLAVE) && !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DATADIR}/helperdata
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${DOCSDIR}/KEY
	${INSTALL_DATA} ${WRKSRC}/fep/README ${DOCSDIR}/README.fep
	${INSTALL_DATA} ${WRKSRC}/fep/README.ja ${DOCSDIR_JA}/README.fep
	${INSTALL_DATA} ${WRKSRC}/xim/README ${DOCSDIR}/README.xim
.endif

.include <bsd.port.post.mk>
