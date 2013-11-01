# Created by: itojun@itojun.org
# $FreeBSD$

PORTNAME=	magicpoint
PORTVERSION=	1.13a
PORTREVISION=	10
CATEGORIES?=	misc
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/mgp/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An X11-based presentation tool

LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		mng:${PORTSDIR}/graphics/libmng
RUN_DEPENDS+=	pnmscale:${PORTSDIR}/graphics/netpbm

MAKE_JOBS_UNSAFE=	yes
NO_STAGE=	yes

USES=		imake:env pkgconfig
USE_XORG=	x11 xext xmu xt sm ice xi xtst
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-vflib --enable-locale
LATE_INSTALL_ARGS=	install.man

MAN1=	mgp.1 mgp2ps.1 mgpembed.1 mgpnet.1 xwintoppm.1 xmindpath.1

PORTDOCS=	${DOCS} sample emacs-lisp scripts
DOCS=		COPYRIGHT COPYRIGHT.jp FAQ README README.fonts \
		README.fonts.jp README.lang RELNOTES SYNTAX TODO.jp \
		USAGE USAGE.jp
SAMPLES=	README README.jp cloud.jpg dad.eps dad.jpg default.mgp \
		embed-jp.mgp embed.mgp gradation-jp.mgp \
		gradation.mgp mgp-old1.jpg mgp-old2.jpg mgp-old3.jpg \
		mgp.mng mgp1.jpg mgp2.jpg mgp3.jpg mgp3.xbm mgprc-sample \
		multilingual.mgp sample-fr.mgp sample-jp.mgp sample.mgp \
		sendmail6-jp.mgp sendmail6.mgp tutorial-jp.mgp \
		tutorial.mgp v6-jp.mgp v6.mgp v6header.eps v6header.jpg
EMACS_LISPS=	mgp-mode.el
EMACS_LISPS_MGP=COPYING README mgp.el mgp.sty sample.tex
SAMPLE_SCRIPTS=	eqn2eps.sh tex2eps.sh mgp2html.pl mgp2latex.pl


OPTIONS_DEFINE=FREETYPE XFT GIF IMLIB
OPTIONS_DEFAULT=FREETYPE XFT
NO_OPTIONS_SORT=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
# Only freetype 1.x is supported
LIB_DEPENDS+=		ttf:${PORTSDIR}/print/freetype
CONFIGURE_ARGS+=	--enable-freetype \
			--enable-freetype-charset16
.else
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
CONFIGURE_ARGS+=	--enable-xft2
.else
CONFIGURE_ARGS+=	--disable-xft2
.endif

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=	gif:${PORTSDIR}/graphics/giflib
CONFIGURE_ARGS+=	--enable-gif
CFLAGS+=	-I${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--disable-gif
.endif

.if ${PORT_OPTIONS:MIMLIB}
USE_GNOME=	imlib
CONFIGURE_ARGS+=	--enable-imlib
.else
CONFIGURE_ARGS+=	--disable-imlib
.endif

post-patch:
	${REINPLACE_CMD} -e 's|-lungif|-lgif|' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/configure

post-configure:
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF} ${XMKMF_ARGS})
	cd ${WRKSRC}/contrib/xmindpath && \
		${SH} ${CONFIGURE_SCRIPT} --prefix=${PREFIX}

post-build:
	cd ${WRKSRC}/contrib/xmindpath && \
		${MAKE}

post-install:
	cd ${WRKSRC}/contrib/xmindpath && \
		${MAKE} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/sample
	cd ${WRKSRC}/sample && \
		${INSTALL_DATA} ${SAMPLES} ${DOCSDIR}/sample/
	${MKDIR} ${DOCSDIR}/emacs-lisp
	cd ${WRKSRC}/contrib && \
		${INSTALL_DATA} ${EMACS_LISPS} ${DOCSDIR}/emacs-lisp/
	${MKDIR} ${DOCSDIR}/emacs-lisp/mgp-el
	cd ${WRKSRC}/contrib/mgp-el && \
		${INSTALL_DATA} ${EMACS_LISPS_MGP} ${DOCSDIR}/emacs-lisp/mgp-el
	${MKDIR} ${DOCSDIR}/scripts
	cd ${WRKSRC}/contrib && \
		${INSTALL_SCRIPT} ${SAMPLE_SCRIPTS} ${DOCSDIR}/scripts/
.endif

.include <bsd.port.mk>
