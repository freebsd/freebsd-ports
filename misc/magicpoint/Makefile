# New ports collection makefile for:	magicpoint
# Date created:		24 December 1997
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#
# "?=" and "+=" are for localized (i.e. Japanese) version

PORTNAME=	magicpoint
PORTVERSION=	1.11b
CATEGORIES+=	misc
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/mgp/

MAINTAINER?=	mita@FreeBSD.org
COMMENT?=	An X11-based presentation tool

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		mng:${PORTSDIR}/graphics/libmng
RUN_DEPENDS+=	pnmscale:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

OPTIONS+=	FREETYPE	"With FreeType support" on \
		XFT		"With Xft2 support" on \
		GIF		"With gif image support" off \
		IMLIB		"With Imlib exclusive image processing" off

MAN1=	mgp.1 mgp2ps.1 mgpembed.1 mgpnet.1 xwintoppm.1 xmindpath.1

DOCS=	COPYRIGHT COPYRIGHT.jp FAQ README README.fonts README.fonts.jp \
	README.lang RELNOTES SYNTAX TODO.jp USAGE USAGE.jp
SAMPLES=	README README.jp cloud.jpg dad.eps dad.jpg default.mgp \
		embed-jp.mgp embed.mgp gradation-jp.mgp \
		gradation.mgp mgp-old1.jpg mgp-old2.jpg mgp-old3.jpg \
		mgp.mng mgp1.jpg mgp2.jpg mgp3.jpg mgp3.xbm mgprc-sample \
		multilingual.mgp sample-fr.mgp sample-jp.mgp sample.mgp \
		sendmail6-jp.mgp sendmail6.mgp tutorial-jp.mgp \
		tutorial.mgp v6-jp.mgp v6.mgp v6header.eps v6header.jpg
EMACS_LISPS=	mgp-mode.el mgp-el/COPYING mgp-el/README \
		mgp-el/mgp.el mgp-el/mgp.sty mgp-el/sample.tex
SAMPLE_SCRIPTS=	eqn2eps.sh tex2eps.sh mgp2html.pl mgp2latex.pl

.include <bsd.port.pre.mk>

.if defined(WITH_FREETYPE)
USE_FREETYPE=	yes
CONFIGURE_ARGS+=	--enable-freetype
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

.if defined(WITH_JAPANESE)
LIB_DEPENDS+=	VFlib2.24:${PORTSDIR}/japanese/vflib
CONFIGURE_ARGS+=	--enable-vflib \
			--with-vfontcap=`${LS} -1 ${LOCALBASE}/share/VFlib/*/vfontcap | tail -1` \
			--enable-freetype-charset16
.else
CONFIGURE_ARGS+=	--disable-vflib
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|varargs.h|stdarg.h|' \
		${WRKSRC}/image/rlelib.c

post-configure:
	(cd ${WRKSRC}/contrib/xmindpath; ./configure --prefix=${PREFIX})

post-build:
	(cd ${WRKSRC}/contrib/xmindpath; make)

# NOTE: there are some discussions/twists in gzip'ing xmindpath.1.
post-install:
	(cd ${WRKSRC}/contrib/xmindpath; make install)
	${GZIP_CMD} ${PREFIX}/man/man1/xmindpath.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mgp
	for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/mgp; \
	done
	${MKDIR} ${PREFIX}/share/doc/mgp/sample
	for i in $(SAMPLES); do \
		${INSTALL_DATA} ${WRKSRC}/sample/$$i ${PREFIX}/share/doc/mgp/sample; \
	done
	${MKDIR} ${PREFIX}/share/doc/mgp/emacs-lisp/mgp-el
	for i in $(EMACS_LISPS); do \
		${INSTALL_DATA} ${WRKSRC}/contrib/$$i ${PREFIX}/share/doc/mgp/emacs-lisp/$$i; \
	done
	${MKDIR} ${PREFIX}/share/doc/mgp/scripts
	for i in $(SAMPLE_SCRIPTS); do \
		${INSTALL_SCRIPT} ${WRKSRC}/contrib/$$i ${PREFIX}/share/doc/mgp/scripts/$$i; \
	done
.endif

.include <bsd.port.post.mk>
