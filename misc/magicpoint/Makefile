# Created by: itojun@itojun.org
# $FreeBSD$

PORTNAME=	magicpoint
PORTVERSION=	1.13a
PORTREVISION=	18
CATEGORIES?=	misc
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/mgp/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	X11-based presentation tool

LICENSE=	BSD3CLAUSE

LIB_DEPENDS+=	libpng.so:graphics/png \
		libmng.so:graphics/libmng
RUN_DEPENDS+=	pnmscale:graphics/netpbm

MAKE_JOBS_UNSAFE=	yes

USES=		imake:env perl5 pkgconfig
USE_PERL5=	run
USE_XORG=	x11 xext xmu xt sm ice xi xtst
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-vflib --enable-locale
CONFIGURE_ENV=	mgp_cv_path_perl=${PERL}
CPPFLAGS+=	-I..
LATE_INSTALL_ARGS=	install.man

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

OPTIONS_DEFINE=	FREETYPE XFT GIF DOCS
OPTIONS_DEFAULT=XFT GIF
NO_OPTIONS_SORT=yes

FREETYPE_PREVENTS=	XFT
FREETYPE_CONFIGURE_ENABLE=	freetype
FREETYPE_LIB_DEPENDS=	libttf.so:print/freetype
XFT_PREVENTS=	FREETYPE
XFT_USES=	iconv
XFT_USE=	XORG=xft
XFT_CONFIGURE_ENABLE=	xft2
XFT_CONFIGURE_ON=	--enable-freetype-charset16
GIF_CONFIGURE_ENABLE=	gif
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CPPFLAGS=		-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|-lungif|-lgif|' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/configure

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${XMKMF} ${XMKMF_ARGS}
	cd ${WRKSRC}/contrib/xmindpath && \
		${SH} ${CONFIGURE_SCRIPT} --prefix=${PREFIX}
	${REINPLACE_CMD} -e 's|freetype1/freetype|freetype1|g' \
		${WRKSRC}/Makefile ${WRKSRC}/image/Makefile

post-build:
	cd ${WRKSRC}/contrib/xmindpath && \
		${MAKE_ENV} ${MAKE} ${MAKE_ARGS}

post-install:
	${INSTALL_MAN} ${WRKSRC}/contrib/xmindpath/xmindpath.1 \
		${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL} ${WRKSRC}/contrib/xmindpath/xmindpath \
		${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/sample
	cd ${WRKSRC}/sample && \
		${INSTALL_DATA} ${SAMPLES} ${STAGEDIR}${DOCSDIR}/sample/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/emacs-lisp
	cd ${WRKSRC}/contrib && \
		${INSTALL_DATA} ${EMACS_LISPS} \
		${STAGEDIR}${DOCSDIR}/emacs-lisp/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/emacs-lisp/mgp-el
	cd ${WRKSRC}/contrib/mgp-el && \
		${INSTALL_DATA} ${EMACS_LISPS_MGP} \
		${STAGEDIR}${DOCSDIR}/emacs-lisp/mgp-el/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/scripts
	cd ${WRKSRC}/contrib && \
		${INSTALL_SCRIPT} ${SAMPLE_SCRIPTS} \
		${STAGEDIR}${DOCSDIR}/scripts/

.include <bsd.port.mk>
