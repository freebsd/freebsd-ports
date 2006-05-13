# New ports collection makefile for:   uim
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uim
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES?=	textproc
MASTER_SITES=	http://uim.freedesktop.org/releases/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Input method library

USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
WANT_GNOME=	yes
USE_GNOME+=	gnometarget glib20
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
.if !defined(UIM_SLAVE)
USE_GNOME+=	gtk20
.endif

LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft

.if !defined(UIM_SLAVE)
CONFIGURE_ARGS=	--enable-emacs --with-gtk2
.endif
CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib  -L${LOCALBASE}/lib"

.if !defined(UIM_SLAVE)
MAN1=		uim-xim.1
DOCSDIR_JA=	${PREFIX}/share/doc/ja/uim
PLIST_SUB=	DOCSDIR_JA="${DOCSDIR_JA:S,^${PREFIX}/,,}"
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_editline.c
.endif

.if ${PERL_LEVEL} >= 500600
USE_PERL5_BUILD=yes
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:${PORTSDIR}/lang/perl5
CONFIGURE_ENV+=	INTLTOOL_PERL="${LOCALBASE}/bin/perl"
.endif

.for _x in gtk2 qt gnome2 anthy canna m17nlib prime scim
.if ${CONFIGURE_ARGS:M--with-${_x}} == ""
CONFIGURE_ARGS+=--without-${_x}
.endif
.endfor
.if ${CONFIGURE_ARGS:M--enable-applet} == ""
CONFIGURE_ARGS+=--disable-applet
.endif

.if !defined(UIM_SLAVE)
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} "Optional features are splitted into the following slave ports."
	@${ECHO_MSG} "OPTIONS variable is no longer used."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "japanese/uim-anthy"
	@${ECHO_MSG} "japanese/uim-canna"
	@${ECHO_MSG} "japanese/uim-prime"
	@${ECHO_MSG} "textproc/uim-gnome"
	@${ECHO_MSG} "textproc/uim-gtk"
	@${ECHO_MSG} "textproc/uim-m17nlib"
	@${ECHO_MSG} "textproc/uim-qt"
	@${ECHO_MSG} ""
.endif

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/scm/skk-custom.scm

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
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${DOCSDIR}/KEY
	${INSTALL_DATA} ${WRKSRC}/fep/README ${DOCSDIR}/README.fep
	${INSTALL_DATA} ${WRKSRC}/fep/README.ja ${DOCSDIR_JA}/README.fep
	${INSTALL_DATA} ${WRKSRC}/xim/README ${DOCSDIR}/README.xim
.endif

.include <bsd.port.post.mk>
