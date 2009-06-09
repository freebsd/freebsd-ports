# New ports collection makefile for:	magicpoint
# Date created:		24 December 1997
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	magicpoint
PORTVERSION=	1.13a
PORTREVISION=	2
CATEGORIES?=	misc
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/mgp/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An X11-based presentation tool

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		mng:${PORTSDIR}/graphics/libmng
RUN_DEPENDS+=	pnmscale:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
USE_XORG=	x11 xext xmu xt sm ice xi xtst
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-vflib

OPTIONS+=	FREETYPE	"With FreeType support" on \
		XFT		"With Xft2 support" on \
		GIF		"With gif image support" off \
		IMLIB		"With Imlib exclusive image processing" off

MAN1=	mgp.1 mgp2ps.1 mgpembed.1 mgpnet.1 xwintoppm.1 xmindpath.1

PORTDOCS=	${DOCS} sample emacs-lisp scripts
DOCS=	COPYRIGHT COPYRIGHT.jp FAQ README README.fonts README.fonts.jp \
	README.lang RELNOTES SYNTAX TODO.jp USAGE USAGE.jp
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

.include <bsd.port.pre.mk>

.if defined(WITH_FREETYPE)
USE_FREETYPE=	yes
CONFIGURE_ARGS+=	--enable-freetype \
			--enable-freetype-charset16
.else
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if defined(WITH_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft2
.else
CONFIGURE_ARGS+=	--disable-xft2
.endif

.if defined(WITH_GIF)
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
CONFIGURE_ARGS+=	--enable-gif
.else
CONFIGURE_ARGS+=	--disable-gif
.endif

.if defined(WITH_IMLIB)
LIB_DEPENDS+=	Imlib.5:${PORTSDIR}/graphics/imlib
CONFIGURE_ARGS+=	--enable-imlib
.else
CONFIGURE_ARGS+=	--disable-imlib
.endif

post-configure:
	cd ${WRKSRC}/contrib/xmindpath && \
		${SH} ${CONFIGURE_SCRIPT} --prefix=${PREFIX}

post-build:
	cd ${WRKSRC}/contrib/xmindpath && \
		${MAKE}

post-install:
	cd ${WRKSRC}/contrib/xmindpath && \
		${MAKE} ${INSTALL_TARGET}
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

.include <bsd.port.post.mk>
